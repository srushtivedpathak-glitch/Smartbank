#include "../include/TransactionRepository.h"
#include <iostream>

TransactionRepository::TransactionRepository(Database* db)
{
    database = db;
}

bool TransactionRepository::addTransaction(const Transaction& transaction)
{
    MYSQL* connection = database->getConnection();

    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return false;
    }

    std::string query =
        "INSERT INTO transactions "
        "(transaction_id, account_no, transaction_type, amount, transaction_date) "
        "VALUES (" +
        std::to_string(transaction.getTransactionId()) + ", " +
        std::to_string(transaction.getAccountNo()) + ", '" +
        transaction.getTransactionType() + "', " +
        std::to_string(transaction.getAmount()) + ", '" +
        transaction.getTransactionDate() + "')";

    if (mysql_query(connection, query.c_str()) != 0)
    {
        std::cout << "Failed to add transaction: "
                  << mysql_error(connection) << std::endl;

        return false;
    }

    std::cout << "Transaction added successfully." << std::endl;
    return true;
}

void TransactionRepository::displayTransactions(long long accountNo)
{
    MYSQL* connection = database->getConnection();

    if (connection == nullptr)
    {
        std::cout << "Database is not connected." << std::endl;
        return;
    }

    std::string query =
        "SELECT transaction_id, account_no, transaction_type, "
        "amount, transaction_date "
        "FROM transactions WHERE account_no = " +
        std::to_string(accountNo);

    if (mysql_query(connection, query.c_str()) != 0)
    {
        std::cout << "Failed to retrieve transactions: "
                  << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);

    if (result == nullptr)
    {
        std::cout << "No transaction data found." << std::endl;
        return;
    }

    MYSQL_ROW row;

    std::cout << "\nTransactions for Account "
              << accountNo << ":\n";

    while ((row = mysql_fetch_row(result)) != nullptr)
    {
        std::cout << "Transaction ID: " << row[0] << std::endl;
        std::cout << "Account No: " << row[1] << std::endl;
        std::cout << "Type: " << row[2] << std::endl;
        std::cout << "Amount: " << row[3] << std::endl;
        std::cout << "Date: " << row[4] << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    mysql_free_result(result);
}