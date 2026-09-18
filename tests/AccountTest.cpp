#include "../include/Account.h"
#include <iostream>

using namespace std;

int main()
{
    Account account;

    cout << "===== ACCOUNT TEST =====" << endl;

    account.addAccount();
    account.viewAccount();
    account.searchAccount();

    return 0;
}
