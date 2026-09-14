#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer
{
private:
    int customer_id;
    string firstName;
    string lastName;
    string phoneNo;
    string email;
    string dob;
    string address;
    string gender;

public:
    Customer();

    void addCustomer();
    void viewCustomer();
    void searchCustomer();
    void updateCustomer();
    void deleteCustomer();

    int getCustomerId();
};

#endif
