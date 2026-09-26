#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Database;

class Account
{
protected:
    long long account_no;
    int customer_id;
    std::string account_type;
    double balance;
    std::string opening_date;
    int branch_id;

public:
    explicit Account(Database* db = nullptr);

    void addAccount();
    void viewAccount();
    void searchAccount();
    void deposit();
    void withdraw();

    long long getAccountNo();

protected:
    Database* database;
};

#endif
