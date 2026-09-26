#include "../include/Loan.h"
#include <iostream>

using namespace std;

int main()
{
    Loan loan;

    cout << "===== LOAN TEST =====" << endl;

    loan.applyLoan();
    loan.viewLoan();
    loan.calculateInterest();

    return 0;
}