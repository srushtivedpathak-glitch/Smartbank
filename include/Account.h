#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
protected:
    long long account_no;
    int customer_id;
    string account_type;
    double balance;
    string opening_date;
    int branch_id;

public:
    Account();

    void addAccount();
    void viewAccount();
    void searchAccount();
    void deposit();
    void withdraw();

    long long getAccountNo();
};

#endif
