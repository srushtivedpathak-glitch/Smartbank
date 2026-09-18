#include "Customer.h"
#include <iostream>

using namespace std;

// Constructor
Customer::Customer()
{
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

    cout << "\nCustomer added successfully!" << endl;
}

// View Customer
void Customer::viewCustomer()
{
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

    cout << "\nCustomer updated successfully!" << endl;
}

// Delete Customer
void Customer::deleteCustomer()
{
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