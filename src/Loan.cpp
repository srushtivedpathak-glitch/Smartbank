#include "Loan.h"
#include <iostream>

using namespace std;

// Constructor
Loan::Loan()
{
    loan_id = 0;
    customer_id = 0;
    loan_type = "";
    loan_amount = 0.0;
    interest_rate = 0.0;
    loan_date = "";
    loan_status = "";
}

// Apply for Loan

void Loan::applyLoan()
{
    cout << "Enter Loan ID: ";
    cin >> loan_id;

    cout << "Enter Customer ID: ";
    cin >> customer_id;

    cin.ignore();

    cout << "Enter Loan Type: ";
    getline(cin, loan_type);

    cout << "Enter Loan Amount: ";
    cin >> loan_amount;

    cout << "Enter Interest Rate: ";
    cin >> interest_rate;

    cin.ignore();

    cout << "Enter Loan Date: ";
    getline(cin, loan_date);

    cout << "Enter Loan Status: ";
    getline(cin, loan_status);

    cout << "\nLoan applied successfully!" << endl;
}
// View Loan
void Loan::viewLoan()
{
    cout << "\n----- Loan Details -----" << endl;
    cout << "Loan ID       : " << loan_id << endl;
    cout << "Customer ID   : " << customer_id << endl;
    cout << "Loan Type     : " << loan_type << endl;
    cout << "Loan Amount   : " << loan_amount << endl;
    cout << "Interest Rate : " << interest_rate << "%" << endl;
    cout << "Loan Date     : " << loan_date << endl;
    cout << "Loan Status   : " << loan_status << endl;
}

// Search Customer's Loans
void Loan::searchCustomerLoans()
{
    int id;

    cout << "Enter Customer ID to search loans: ";
    cin >> id;

    if (id == customer_id)
    {
        cout << "\nLoan found for customer!" << endl;
        viewLoan();
    }
    else
    {
        cout << "\nNo loan found for this customer!" << endl;
    }
}

// Update Loan Status
void Loan::updateLoanStatus()
{
    cout << "Enter new Loan Status: ";
    cin >> loan_status;

    cout << "\nLoan status updated successfully!" << endl;
}

// Calculate Interest
void Loan::calculateInterest()
{
    double interest;

    interest = (loan_amount * interest_rate) / 100;

    cout << "\nInterest Amount: " << interest << endl;
}

// Get Loan ID
int Loan::getLoanId()
{
    return loan_id;
}