#include "SavingAccount.h"
#include <iostream>

using namespace std;

// Constructor
SavingAccount::SavingAccount()
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
