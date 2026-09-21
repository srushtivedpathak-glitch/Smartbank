#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount : public Account
{
private:
    double interest_rate;

public:
    explicit SavingAccount(Database* db = nullptr);

    void calculateInterest();
    void viewSavingAccount();

    double getInterestRate();
};

#endif
