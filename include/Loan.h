#ifndef LOAN_H
#define LOAN_H

#include <string>
using namespace std;

class Loan
{
private:
    int loan_id;
    int customer_id;
    string loan_type;
    double loan_amount;
    double interest_rate;
    string loan_date;
    string loan_status;

public:
    Loan();

    void applyLoan();
    void viewLoan();
    void searchCustomerLoans();
    void updateLoanStatus();
    void calculateInterest();

    int getLoanId();
};

#endif