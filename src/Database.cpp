#include "../include/Database.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Database::Database()
{
    connection = nullptr;
}

bool Database::connect()
{
    connection = mysql_init(nullptr);

    if (connection == nullptr)
    {
        std::cout << "MySQL initialization failed." << std::endl;
        return false;
    }

    if (mysql_real_connect(
            connection,
            "localhost",
            "root",
            "27062007",
            "smartbank",
            3306,
            nullptr,
            0) == nullptr)
    {
        std::cout << "Database connection failed: "
                  << mysql_error(connection) << std::endl;

        mysql_close(connection);
        connection = nullptr;

        return false;
    }

    std::cout << "Database connected successfully." << std::endl;
    return true;
}

void Database::disconnect()
{
    if (connection != nullptr)
    {
        mysql_close(connection);
        connection = nullptr;
    }
}

MYSQL* Database::getConnection()
{
    return connection;
}

std::string Database::escape(const std::string& value)
{
    if (connection == nullptr)
    {
        return value;
    }

    std::string escaped(value.size() * 2 + 1, '\0');
    unsigned long length = mysql_real_escape_string(
        connection,
        &escaped[0],
        value.c_str(),
        static_cast<unsigned long>(value.size()));
    escaped.resize(length);
    return escaped;
}


// --------------------------------------------------
// DEPOSIT
// --------------------------------------------------

bool Database::deposit(long long accountNo, double amount)
{
    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return false;
    }

    if (amount <= 0)
    {
        std::cout << "Invalid deposit amount." << std::endl;
        return false;
    }

    // Start transaction
    if (mysql_query(connection, "START TRANSACTION") != 0)
    {
        std::cout << "Could not start database transaction: "
                  << mysql_error(connection) << std::endl;
        return false;
    }

    // Update account balance
    std::stringstream updateQuery;

    updateQuery << std::fixed << std::setprecision(2);

    updateQuery
        << "UPDATE accounts "
        << "SET balance = balance + " << amount
        << " WHERE account_no = " << accountNo;

    if (mysql_query(connection, updateQuery.str().c_str()) != 0)
    {
        std::cout << "Deposit failed: "
                  << mysql_error(connection) << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    // Make sure account exists
    if (mysql_affected_rows(connection) == 0)
    {
        std::cout << "Account not found." << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    if (mysql_query(connection, "COMMIT") != 0)
    {
        std::cout << "Could not commit deposit: "
                  << mysql_error(connection) << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    std::cout << "Deposit successful." << std::endl;

    return true;
}


// --------------------------------------------------
// WITHDRAW
// --------------------------------------------------

bool Database::withdraw(long long accountNo, double amount)
{
    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return false;
    }

    if (amount <= 0)
    {
        std::cout << "Invalid withdrawal amount." << std::endl;
        return false;
    }

    // Start transaction
    if (mysql_query(connection, "START TRANSACTION") != 0)
    {
        std::cout << "Could not start database transaction: "
                  << mysql_error(connection) << std::endl;
        return false;
    }

    /*
       For Savings accounts:
       balance must remain >= 1000.

       For Current accounts:
       the database allows the balance to go below 1000,
       subject to the application's withdrawal rules.
    */

    std::stringstream query;

    query << std::fixed << std::setprecision(2);

    query
        << "UPDATE accounts "
        << "SET balance = balance - " << amount
        << " WHERE account_no = " << accountNo
        << " AND ("
        << "Account_type <> 'Savings' "
        << "OR balance - " << amount << " >= 1000"
        << ")";

    if (mysql_query(connection, query.str().c_str()) != 0)
    {
        std::cout << "Withdrawal failed: "
                  << mysql_error(connection) << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    if (mysql_affected_rows(connection) == 0)
    {
        std::cout
            << "Withdrawal failed. Account not found or "
            << "minimum balance requirement would be violated."
            << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    if (mysql_query(connection, "COMMIT") != 0)
    {
        std::cout << "Could not commit withdrawal: "
                  << mysql_error(connection) << std::endl;

        mysql_query(connection, "ROLLBACK");
        return false;
    }

    std::cout << "Withdrawal successful." << std::endl;

    return true;
}

bool Database::recordAccountTransaction(
    long long accountNo,
    const std::string& transactionType,
    double amount)
{
    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return false;
    }

    if (amount <= 0 ||
        (transactionType != "Deposit" && transactionType != "Withdrawal"))
    {
        std::cout << "Invalid account transaction." << std::endl;
        return false;
    }

    if (mysql_query(connection, "START TRANSACTION") != 0)
    {
        std::cout << "Could not start database transaction: "
                  << mysql_error(connection) << std::endl;
        return false;
    }

    std::stringstream amountText;
    amountText << std::fixed << std::setprecision(2) << amount;

    std::string updateQuery;
    if (transactionType == "Deposit")
    {
        updateQuery =
            "UPDATE accounts SET balance = balance + " + amountText.str() +
            " WHERE account_no = " + std::to_string(accountNo);
    }
    else
    {
        updateQuery =
            "UPDATE accounts a LEFT JOIN currentaccount c ON c.account_no = a.account_no "
            "SET a.balance = a.balance - " + amountText.str() +
            " WHERE a.account_no = " + std::to_string(accountNo) +
            " AND (a.Account_type <> 'Savings' OR a.balance - " + amountText.str() + " >= 1000)"
            " AND (a.Account_type <> 'Current' OR "
            "(c.overdraft_limit IS NOT NULL AND a.balance - " + amountText.str() +
            " >= -c.overdraft_limit))";
    }

    if (mysql_query(connection, updateQuery.c_str()) != 0 ||
        mysql_affected_rows(connection) == 0)
    {
        std::cout << "Account update failed: " << mysql_error(connection) << std::endl;
        mysql_query(connection, "ROLLBACK");
        return false;
    }

    if (mysql_query(
            connection,
            "SELECT COALESCE(MAX(transaction_id), 0) + 1 FROM transactions") != 0)
    {
        std::cout << "Could not generate transaction ID: "
                  << mysql_error(connection) << std::endl;
        mysql_query(connection, "ROLLBACK");
        return false;
    }

    MYSQL_RES* result = mysql_store_result(connection);
    MYSQL_ROW row = result == nullptr ? nullptr : mysql_fetch_row(result);
    if (row == nullptr)
    {
        if (result != nullptr) mysql_free_result(result);
        mysql_query(connection, "ROLLBACK");
        return false;
    }

    int transactionId = std::stoi(row[0]);
    mysql_free_result(result);

    std::string insertQuery =
        "INSERT INTO transactions "
        "(transaction_id, account_no, transaction_type, amount, transaction_date) VALUES (" +
        std::to_string(transactionId) + ", " + std::to_string(accountNo) + ", '" +
        transactionType + "', " + amountText.str() + ", NOW())";

    if (mysql_query(connection, insertQuery.c_str()) != 0)
    {
        std::cout << "Could not add transaction: "
                  << mysql_error(connection) << std::endl;
        mysql_query(connection, "ROLLBACK");
        return false;
    }

    if (mysql_query(connection, "COMMIT") != 0)
    {
        std::cout << "Could not commit account transaction: "
                  << mysql_error(connection) << std::endl;
        mysql_query(connection, "ROLLBACK");
        return false;
    }

    std::cout << transactionType << " successful. Transaction ID: "
              << transactionId << std::endl;
    return true;
}


// --------------------------------------------------
// ADD TRANSACTION
// --------------------------------------------------

bool Database::addTransaction(
    int transactionId,
    long long accountNo,
    const std::string& transactionType,
    double amount)
{
    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return false;
    }

    if (amount <= 0)
    {
        std::cout << "Invalid transaction amount." << std::endl;
        return false;
    }

    if (transactionType != "Deposit" &&
        transactionType != "Withdrawal")
    {
        std::cout << "Invalid transaction type." << std::endl;
        return false;
    }

    std::stringstream query;

    query << std::fixed << std::setprecision(2);

    query
        << "INSERT INTO transactions "
        << "(transaction_id, account_no, transaction_type, amount, transaction_date) "
        << "VALUES ("
        << transactionId << ", "
        << accountNo << ", '"
        << transactionType << "', "
        << amount << ", NOW())";

    if (mysql_query(connection, query.str().c_str()) != 0)
    {
        std::cout << "Could not add transaction: "
                  << mysql_error(connection) << std::endl;

        return false;
    }

    return true;
}


// --------------------------------------------------
// VIEW TRANSACTIONS
// --------------------------------------------------

void Database::viewTransactions(long long accountNo)
{
    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return;
    }

    std::stringstream query;

    query
        << "SELECT transaction_id, transaction_type, amount, "
        << "transaction_date "
        << "FROM transactions "
        << "WHERE account_no = " << accountNo
        << " ORDER BY transaction_date DESC";

    if (mysql_query(connection, query.str().c_str()) != 0)
    {
        std::cout << "Could not retrieve transactions: "
                  << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);

    if (result == nullptr)
    {
        std::cout << "Could not read transaction data: "
                  << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_ROW row;

    std::cout << "\n========================================\n";
    std::cout << "       TRANSACTION HISTORY\n";
    std::cout << "========================================\n";

    bool found = false;

    while ((row = mysql_fetch_row(result)) != nullptr)
    {
        found = true;

        std::cout << "Transaction ID : " << row[0] << std::endl;
        std::cout << "Type           : " << row[1] << std::endl;
        std::cout << "Amount         : " << row[2] << std::endl;
        std::cout << "Date           : " << row[3] << std::endl;
        std::cout << "----------------------------------------\n";
    }

    if (!found)
    {
        std::cout << "No transactions found for this account.\n";
    }

    mysql_free_result(result);
}