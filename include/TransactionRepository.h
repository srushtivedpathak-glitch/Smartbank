#ifndef TRANSACTION_REPOSITORY_H
#define TRANSACTION_REPOSITORY_H

#include "Transaction.h"
#include "Database.h"

class TransactionRepository
{
private:
    Database* database;

public:
    TransactionRepository(Database* db);

    bool addTransaction(const Transaction& transaction);
    void displayTransactions(long long accountNo);
};

#endif