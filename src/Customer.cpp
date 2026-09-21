#include "Customer.h"
#include "../include/Database.h"
#include <iostream>

using namespace std;

// Constructor
Customer::Customer(Database* db)
{
    database = db;
    customer_id = 0;
    firstName = "";
    lastName = "";
    phoneNo = "";
    email = "";
    dob = "";
    address = "";
    gender = "";
}

// Add Customer
void Customer::addCustomer()
{
    cout << "Enter Customer ID: ";
    cin >> customer_id;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    cout << "Enter Phone Number: ";
    cin >> phoneNo;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter DOB: ";
    cin >> dob;

    cin.ignore();

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Gender: ";
    cin >> gender;

    if (database != nullptr && database->getConnection() != nullptr)
    {
        string query =
            "INSERT INTO customer "
            "(customer_id, Firstname, Lastname, Phoneno, Email, DOB, Address, Gender) VALUES (" +
            to_string(customer_id) + ", '" + database->escape(firstName) + "', '" +
            database->escape(lastName) + "', '" + database->escape(phoneNo) + "', '" +
            database->escape(email) + "', '" + database->escape(dob) + "', '" +
            database->escape(address) + "', '" + database->escape(gender) + "')";

        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to add customer: "
                 << mysql_error(database->getConnection()) << endl;
            return;
        }
    }

    cout << "\nCustomer added successfully!" << endl;
}

// View Customer
void Customer::viewCustomer()
{
    if (database != nullptr && database->getConnection() != nullptr)
    {
        const char* query =
            "SELECT customer_id, Firstname, Lastname, Phoneno, Email, DOB, Address, Gender "
            "FROM customer ORDER BY customer_id";

        if (mysql_query(database->getConnection(), query) != 0)
        {
            cout << "Failed to retrieve customers: "
                 << mysql_error(database->getConnection()) << endl;
            return;
        }

        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row;
        while (result != nullptr && (row = mysql_fetch_row(result)) != nullptr)
        {
            cout << "\nCustomer ID : " << row[0] << endl;
            cout << "First Name  : " << row[1] << endl;
            cout << "Last Name   : " << row[2] << endl;
            cout << "Phone No    : " << row[3] << endl;
            cout << "Email       : " << row[4] << endl;
            cout << "DOB         : " << row[5] << endl;
            cout << "Address     : " << row[6] << endl;
            cout << "Gender      : " << row[7] << endl;
        }
        if (result != nullptr)
        {
            mysql_free_result(result);
        }
        return;
    }

    cout << "\n----- Customer Details -----" << endl;
    cout << "Customer ID : " << customer_id << endl;
    cout << "First Name  : " << firstName << endl;
    cout << "Last Name   : " << lastName << endl;
    cout << "Phone No    : " << phoneNo << endl;
    cout << "Email       : " << email << endl;
    cout << "DOB         : " << dob << endl;
    cout << "Address     : " << address << endl;
    cout << "Gender      : " << gender << endl;
}

// Search Customer
void Customer::searchCustomer()
{
    int id;

    cout << "Enter Customer ID to search: ";
    cin >> id;

    if (database != nullptr && database->getConnection() != nullptr)
    {
        string query =
            "SELECT customer_id, Firstname, Lastname, Phoneno, Email, DOB, Address, Gender "
            "FROM customer WHERE customer_id = " + to_string(id);

        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to search customer: "
                 << mysql_error(database->getConnection()) << endl;
            return;
        }

        MYSQL_RES* result = mysql_store_result(database->getConnection());
        MYSQL_ROW row = result == nullptr ? nullptr : mysql_fetch_row(result);
        if (row == nullptr)
        {
            cout << "\nCustomer not found!" << endl;
        }
        else
        {
            cout << "\nCustomer found!" << endl;
            cout << "Customer ID : " << row[0] << endl;
            cout << "First Name  : " << row[1] << endl;
            cout << "Last Name   : " << row[2] << endl;
            cout << "Phone No    : " << row[3] << endl;
            cout << "Email       : " << row[4] << endl;
            cout << "DOB         : " << row[5] << endl;
            cout << "Address     : " << row[6] << endl;
            cout << "Gender      : " << row[7] << endl;
        }
        if (result != nullptr)
        {
            mysql_free_result(result);
        }
        return;
    }

    if (id == customer_id)
    {
        cout << "\nCustomer found!" << endl;
        viewCustomer();
    }
    else
    {
        cout << "\nCustomer not found!" << endl;
    }
}

// Update Customer
void Customer::updateCustomer()
{
    cout << "\nEnter new Phone Number: ";
    cin >> phoneNo;

    cout << "Enter new Email: ";
    cin >> email;

    cin.ignore();

    cout << "Enter new Address: ";
    getline(cin, address);

    if (database != nullptr && database->getConnection() != nullptr)
    {
        string query =
            "UPDATE customer SET Phoneno = '" + database->escape(phoneNo) +
            "', Email = '" + database->escape(email) + "', Address = '" +
            database->escape(address) + "' WHERE customer_id = " +
            to_string(customer_id);

        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to update customer: "
                 << mysql_error(database->getConnection()) << endl;
            return;
        }
    }

    cout << "\nCustomer updated successfully!" << endl;
}

// Delete Customer
void Customer::deleteCustomer()
{
    if (database != nullptr && database->getConnection() != nullptr)
    {
        cout << "Enter Customer ID to delete: ";
        cin >> customer_id;

        string query = "DELETE FROM customer WHERE customer_id = " +
                       to_string(customer_id);
        if (mysql_query(database->getConnection(), query.c_str()) != 0)
        {
            cout << "Failed to delete customer: "
                 << mysql_error(database->getConnection()) << endl;
            return;
        }
        cout << "\nCustomer deleted successfully!" << endl;
        return;
    }

    customer_id = 0;
    firstName = "";
    lastName = "";
    phoneNo = "";
    email = "";
    dob = "";
    address = "";
    gender = "";

    cout << "\nCustomer deleted successfully!" << endl;
}

// Get Customer ID
int Customer::getCustomerId()
{
    return customer_id;
}