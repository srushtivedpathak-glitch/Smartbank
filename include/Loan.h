#ifndef LOAN_H
#define LOAN_H

#include <string>

class Database;

class Loan
{
private:
    int loan_id;
    int customer_id;
    std::string loan_type;
    double loan_amount;
    double interest_rate;
    std::string loan_date;
    std::string loan_status;

public:
    explicit Loan(Database* db = nullptr);

    void applyLoan();
    void viewLoan();
    void searchCustomerLoans();
    void updateLoanStatus();
    void calculateInterest();

    int getLoanId();

private:
    Database* database;
};

#endif