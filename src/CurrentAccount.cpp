#include "CurrentAccount.h"
#include "../include/Database.h"
#include <iostream>

using namespace std;

// Constructor
CurrentAccount::CurrentAccount(Database* db) : Account(db)
{
    account_no = 0;
    customer_id = 0;
    account_type = "Current";
    balance = 0.0;
    opening_date = "";
    branch_id = 0;
    overdraft_limit = 50000.00;
}

// Withdraw with Overdraft
void CurrentAccount::withdrawWithOverdraft()
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= (balance + overdraft_limit))
    {
        balance = balance - amount;

        cout << "\nAmount withdrawn successfully!" << endl;
        cout << "Current Balance: " << balance << endl;

        if (balance < 0)
        {
            cout << "Overdraft Used : " << -balance << endl;
        }
    }
    else
    {
        cout << "\nWithdrawal exceeds available balance and overdraft limit!" << endl;
    }
}

// View Current Account
void CurrentAccount::viewCurrentAccount()
{
    if (database != nullptr && database->getConnection() != nullptr)
    {
        const char* query =
            "SELECT a.account_no, a.customer_id, a.Account_type, a.balance, "
            "a.opening_date, a.branch_id, c.overdraft_limit "
            "FROM accounts a JOIN currentaccount c ON c.account_no = a.account_no "
            "ORDER BY a.account_no";
        if (mysql_query(database->getConnection(), query) != 0)
        {
            cout << "Failed to retrieve current accounts: " << mysql_error(database->getConnection()) << endl;
            return;
        }
        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row;
        while (result != nullptr && (row = mysql_fetch_row(result)) != nullptr)
        {
            cout << "\nAccount No      : " << row[0] << endl;
            cout << "Customer ID     : " << row[1] << endl;
            cout << "Account Type    : " << row[2] << endl;
            cout << "Balance         : " << row[3] << endl;
            cout << "Opening Date    : " << row[4] << endl;
            cout << "Branch ID       : " << row[5] << endl;
            cout << "Overdraft Limit : " << row[6] << endl;
        }
        if (result != nullptr) mysql_free_result(result);
        return;
    }

    cout << "\n----- Current Account Details -----" << endl;
    cout << "Account No      : " << account_no << endl;
    cout << "Customer ID     : " << customer_id << endl;
    cout << "Account Type    : " << account_type << endl;
    cout << "Balance         : " << balance << endl;
    cout << "Opening Date    : " << opening_date << endl;
    cout << "Branch ID       : " << branch_id << endl;
    cout << "Overdraft Limit : " << overdraft_limit << endl;
}

// Get Overdraft Limit
double CurrentAccount::getOverdraftLimit()
{
    return overdraft_limit;
}
