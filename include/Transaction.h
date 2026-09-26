#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction
{
private:
    int transactionId;
    long long accountNo;
    double amount;
    std::string transactionType;
    std::string transactionDate;

public:
    Transaction();

    void setTransactionId(int id);
    void setAccountNo(long long account);
    void setAmount(double value);
    void setTransactionType(const std::string& type);
    void setTransactionDate(const std::string& date);

    int getTransactionId() const;
    long long getAccountNo() const;
    double getAmount() const;
    std::string getTransactionType() const;
    std::string getTransactionDate() const;
};

#endif