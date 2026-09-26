#include "../include/Transaction.h"

Transaction::Transaction()
{
    transactionId = 0;
    accountNo = 0;
    amount = 0.0;
    transactionDate = "";
    transactionType = "";
}

void Transaction::setTransactionId(int id)
{
    transactionId = id;
}

void Transaction::setAccountNo(long long account)
{
    accountNo = account;
}

void Transaction::setAmount(double value)
{
    amount = value;
}

void Transaction::setTransactionType(const std::string& type)
{
    transactionType = type;
}
int Transaction::getTransactionId() const
{
    return transactionId;
}

long long Transaction::getAccountNo() const
{
    return accountNo;
}

double Transaction::getAmount() const
{
    return amount;
}
void Transaction::setTransactionDate(const std::string& date)
{
    transactionDate = date;
}

std::string Transaction::getTransactionDate() const
{
    return transactionDate;
}

std::string Transaction::getTransactionType() const
{
    return transactionType;
}