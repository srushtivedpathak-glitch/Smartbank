#include "../include/Database.h"
#include "../include/Transaction.h"
#include "../include/TransactionRepository.h"
#include <iostream>

int main()
{
    Database db;

    if (!db.connect())
    {
        std::cout << "Database connection failed." << std::endl;
        return 1;
    }

    TransactionRepository repository(&db);

    repository.displayTransactions(100001);

    db.disconnect();

    return 0;
}