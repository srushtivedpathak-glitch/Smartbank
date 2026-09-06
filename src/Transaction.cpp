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

void Transaction::setAccountNo(int account)
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

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getAccountNo()
{
    return accountNo;
}

double Transaction::getAmount()
{
    return amount;
}
void Transaction::setTransactionDate(const std::string& date)
{
    transactionDate = date;
}

std::string Transaction::getTransactionDate()
{
    return transactionDate;
}

std::string Transaction::getTransactionType()
{
    return transactionType;
}