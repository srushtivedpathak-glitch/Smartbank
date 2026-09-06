#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    int transactionId;
    int accountNo;
    double amount;
    std::string transactionType;

public:
    Transaction();

    void setTransactionId(int id);
    void setAccountNo(int account);
    void setAmount(double value);
    void setTransactionType(const std::string& type);

    int getTransactionId();
    int getAccountNo();
    double getAmount();
    std::string getTransactionType();
};

#endif