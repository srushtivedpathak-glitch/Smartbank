#include "SavingAccount.h"
#include "../include/Database.h"
#include <iostream>

using namespace std;

// Constructor
SavingAccount::SavingAccount(Database* db) : Account(db)
{
    account_no = 0;
    customer_id = 0;
    account_type = "Savings";
    balance = 0.0;
    opening_date = "";
    branch_id = 0;
    interest_rate = 4.50;
}

// Calculate Interest
void SavingAccount::calculateInterest()
{
    double interest;

    interest = (balance * interest_rate) / 100;

    cout << "\n----- Savings Account Interest -----" << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Interest Rate : " << interest_rate << "%" << endl;
    cout << "Interest      : " << interest << endl;
}

// View Saving Account
void SavingAccount::viewSavingAccount()
{
    if (database != nullptr && database->getConnection() != nullptr)
    {
        const char* query =
            "SELECT a.account_no, a.customer_id, a.Account_type, a.balance, "
            "a.opening_date, a.branch_id, s.Interest_Rate "
            "FROM accounts a JOIN savingaccount s ON s.account_no = a.account_no "
            "ORDER BY a.account_no";
        if (mysql_query(database->getConnection(), query) != 0)
        {
            cout << "Failed to retrieve saving accounts: " << mysql_error(database->getConnection()) << endl;
            return;
        }
        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row;
        while (result != nullptr && (row = mysql_fetch_row(result)) != nullptr)
        {
            cout << "\nAccount No    : " << row[0] << endl;
            cout << "Customer ID   : " << row[1] << endl;
            cout << "Account Type  : " << row[2] << endl;
            cout << "Balance       : " << row[3] << endl;
            cout << "Opening Date  : " << row[4] << endl;
            cout << "Branch ID     : " << row[5] << endl;
            cout << "Interest Rate : " << row[6] << "%" << endl;
        }
        if (result != nullptr) mysql_free_result(result);
        return;
    }

    cout << "\n----- Saving Account Details -----" << endl;
    cout << "Account No    : " << account_no << endl;
    cout << "Customer ID   : " << customer_id << endl;
    cout << "Account Type  : " << account_type << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Opening Date  : " << opening_date << endl;
    cout << "Branch ID     : " << branch_id << endl;
    cout << "Interest Rate : " << interest_rate << "%" << endl;
}

// Get Interest Rate
double SavingAccount::getInterestRate()
{
    return interest_rate;
}
