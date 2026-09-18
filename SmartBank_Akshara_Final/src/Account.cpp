#include "Account.h"
#include <iostream>

using namespace std;

// Constructor
Account::Account()
{
    account_no = 0;
    customer_id = 0;
    account_type = "";
    balance = 0.0;
    opening_date = "";
    branch_id = 0;
}

// Add Account
void Account::addAccount()
{
    cout << "Enter Account Number: ";
    cin >> account_no;

    cout << "Enter Customer ID: ";
    cin >> customer_id;

    cin.ignore();

    cout << "Enter Account Type: ";
    getline(cin, account_type);

    cout << "Enter Balance: ";
    cin >> balance;

    cin.ignore();

    cout << "Enter Opening Date: ";
    getline(cin, opening_date);

    cout << "Enter Branch ID: ";
    cin >> branch_id;

    cout << "\nAccount added successfully!" << endl;
}

// View Account
void Account::viewAccount()
{
    cout << "\n----- Account Details -----" << endl;
    cout << "Account No    : " << account_no << endl;
    cout << "Customer ID   : " << customer_id << endl;
    cout << "Account Type  : " << account_type << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Opening Date  : " << opening_date << endl;
    cout << "Branch ID     : " << branch_id << endl;
}

// Search Account
void Account::searchAccount()
{
    long long number;

    cout << "Enter Account Number to search: ";
    cin >> number;

    if (number == account_no)
    {
        cout << "\nAccount found!" << endl;
        viewAccount();
    }
    else
    {
        cout << "\nAccount not found!" << endl;
    }
}

// Deposit
void Account::deposit()
{
    double amount;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0)
    {
        balance = balance + amount;
        cout << "\nAmount deposited successfully!" << endl;
        cout << "Updated Balance: " << balance << endl;
    }
    else
    {
        cout << "\nInvalid deposit amount!" << endl;
    }
}

// Withdraw
void Account::withdraw()
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance)
    {
        balance = balance - amount;
        cout << "\nAmount withdrawn successfully!" << endl;
        cout << "Updated Balance: " << balance << endl;
    }
    else
    {
        cout << "\nInsufficient balance or invalid amount!" << endl;
    }
}

// Get Account Number
long long Account::getAccountNo()
{
    return account_no;
}
