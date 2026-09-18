#include "../include/CurrentAccount.h"
#include <iostream>

using namespace std;

int main()
{
    CurrentAccount account;

    cout << "===== CURRENT ACCOUNT TEST =====" << endl;

    account.addAccount();
    account.viewCurrentAccount();
    account.withdrawWithOverdraft();

    return 0;
}
