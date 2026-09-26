#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account
{
private:
    double overdraft_limit;

public:
    explicit CurrentAccount(Database* db = nullptr);

    void withdrawWithOverdraft();
    void viewCurrentAccount();

    double getOverdraftLimit();
};

#endif
