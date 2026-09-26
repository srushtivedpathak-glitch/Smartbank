#include "../include/SavingAccount.h"
#include <iostream>

using namespace std;

int main()
{
    SavingAccount account;

    cout << "===== SAVING ACCOUNT TEST =====" << endl;

    account.addAccount();
    account.viewSavingAccount();
    account.calculateInterest();

    return 0;
}
