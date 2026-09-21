#include "../include/Database.h"
#include <iostream>

int main()
{
    Database db;

    if (!db.connect())
    {
        std::cout << "Connection test FAILED." << std::endl;
        return 1;
    }

    std::cout << "\n--- Testing Deposit ---\n";

    if (db.deposit(100001, 500.00))
    {
        std::cout << "Deposit test PASSED.\n";
    }
    else
    {
        std::cout << "Deposit test FAILED.\n";
    }

    std::cout << "\n--- Testing Withdrawal ---\n";

    if (db.withdraw(100001, 200.00))
    {
        std::cout << "Withdrawal test PASSED.\n";
    }
    else
    {
        std::cout << "Withdrawal test FAILED.\n";
    }

    std::cout << "\n--- Transaction History ---\n";

    db.viewTransactions(100001);

    db.disconnect();

    return 0;
}