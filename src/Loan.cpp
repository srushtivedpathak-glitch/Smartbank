#include "Loan.h"
#include "../include/Database.h"
#include <iostream>

using namespace std;

// Constructor
Loan::Loan(Database* db)
{
    database = db;
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

    if (database != nullptr && database->getConnection() != nullptr)
    {
        string query =
            "INSERT INTO loans (loan_id, customer_id, loan_type, loan_amount, interest_rate, loan_date, loan_status) VALUES (" +
            to_string(loan_id) + ", " + to_string(customer_id) + ", '" +
            database->escape(loan_type) + "', " + to_string(loan_amount) + ", " +
            to_string(interest_rate) + ", '" + database->escape(loan_date) + "', '" +
            database->escape(loan_status) + "')";
        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to apply loan: " << mysql_error(database->getConnection()) << endl;
            return;
        }
    }

    cout << "\nLoan applied successfully!" << endl;
}
// View Loan
void Loan::viewLoan()
{
    if (database != nullptr && database->getConnection() != nullptr)
    {
        if (mysql_query(database->getConnection(),
                        "SELECT loan_id, customer_id, loan_type, loan_amount, interest_rate, loan_date, loan_status FROM loans ORDER BY loan_id") != 0)
        {
            cout << "Failed to retrieve loans: " << mysql_error(database->getConnection()) << endl;
            return;
        }
        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row;
        while (result != nullptr && (row = mysql_fetch_row(result)) != nullptr)
        {
            cout << "\nLoan ID       : " << row[0] << endl;
            cout << "Customer ID   : " << row[1] << endl;
            cout << "Loan Type     : " << row[2] << endl;
            cout << "Loan Amount   : " << row[3] << endl;
            cout << "Interest Rate : " << row[4] << "%" << endl;
            cout << "Loan Date     : " << row[5] << endl;
            cout << "Loan Status   : " << row[6] << endl;
        }
        if (result != nullptr) mysql_free_result(result);
        return;
    }

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

    if (database != nullptr && database->getConnection() != nullptr)
    {
        string query =
            "SELECT loan_id, customer_id, loan_type, loan_amount, interest_rate, loan_date, loan_status FROM loans WHERE customer_id = " +
            to_string(id);
        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to search loans: " << mysql_error(database->getConnection()) << endl;
            return;
        }
        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row;
        bool found = false;
        while (result != nullptr && (row = mysql_fetch_row(result)) != nullptr)
        {
            found = true;
            cout << "\nLoan ID       : " << row[0] << endl;
            cout << "Customer ID   : " << row[1] << endl;
            cout << "Loan Type     : " << row[2] << endl;
            cout << "Loan Amount   : " << row[3] << endl;
            cout << "Interest Rate : " << row[4] << "%" << endl;
            cout << "Loan Date     : " << row[5] << endl;
            cout << "Loan Status   : " << row[6] << endl;
        }
        if (!found) cout << "\nNo loan found for this customer!" << endl;
        if (result != nullptr) mysql_free_result(result);
        return;
    }

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
    if (database != nullptr && database->getConnection() != nullptr)
    {
        cout << "Enter Loan ID: ";
        cin >> loan_id;
        cout << "Enter new Loan Status: ";
        cin >> loan_status;

        string query = "UPDATE loans SET loan_status = '" + database->escape(loan_status) +
                       "' WHERE loan_id = " + to_string(loan_id);
        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to update loan status: " << mysql_error(database->getConnection()) << endl;
            return;
        }
        cout << "\nLoan status updated successfully!" << endl;
        return;
    }

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