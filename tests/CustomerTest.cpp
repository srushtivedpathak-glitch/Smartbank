#include "../include/Customer.h"
#include <iostream>

using namespace std;

int main()
{
    Customer customer;

    cout << "===== CUSTOMER TEST =====" << endl;

    customer.addCustomer();
    customer.viewCustomer();

    return 0;
}