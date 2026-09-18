#include "CurrentAccount.h"
#include <iostream>

using namespace std;

// Constructor
CurrentAccount::CurrentAccount()
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
