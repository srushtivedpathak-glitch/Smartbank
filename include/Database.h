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
    std::string escape(const std::string& value);

    // Account operations
    bool deposit(long long accountNo, double amount);
    bool withdraw(long long accountNo, double amount);
    bool recordAccountTransaction(
        long long accountNo,
        const std::string& transactionType,
        double amount);

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