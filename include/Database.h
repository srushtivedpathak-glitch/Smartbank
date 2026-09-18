#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>
#include <string>

class Database
{
private:
    MYSQL* connection;

public:
    Database();

    bool connect();
    void disconnect();

    MYSQL* getConnection();

    // Account operations
    bool deposit(long long accountNo, double amount);
    bool withdraw(long long accountNo, double amount);

    // Transaction operations
    bool addTransaction(
        int transactionId,
        long long accountNo,
        const std::string& transactionType,
        double amount
    );

    // Display transaction history
    void viewTransactions(long long accountNo);
};

#endif