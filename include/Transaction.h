#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    int transactionId;
    int accountNo;
    double amount;
    std::string transactionDate;
    std::string transactionType;

public:
    Transaction();

    void setTransactionId(int id);
    void setAccountNo(int account);
    void setAmount(double value);
    void setTransactionDate(const std::string& date);
    void setTransactionType(const std::string& type);

    int getTransactionId();
    int getAccountNo();
    double getAmount();
    std::string getTransactionDate();
    std::string getTransactionType();
};

#endif