#ifndef BRANCH_H
#define BRANCH_H

#include <string>
using namespace std;

class Branch
{
private:
    int branch_id;
    string branch_name;
    string city;
    string IFSC_code;

public:
    Branch();

    void viewBranch();
    void searchBranch();
    void displayBranchDetails();

    int getBranchId();
};

#endif