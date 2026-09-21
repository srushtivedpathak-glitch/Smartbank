#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Database;

class Customer
{
private:
    int customer_id;
    std::string firstName;
    std::string lastName;
    std::string phoneNo;
    std::string email;
    std::string dob;
    std::string address;
    std::string gender;

public:
    explicit Customer(Database* db = nullptr);

    void addCustomer();
    void viewCustomer();
    void searchCustomer();
    void updateCustomer();
    void deleteCustomer();

    int getCustomerId();

private:
    Database* database;
};

#endif
