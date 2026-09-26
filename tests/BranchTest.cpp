#include "../include/Branch.h"
#include <iostream>

using namespace std;

int main()
{
    Branch branch;

    cout << "===== BRANCH TEST =====" << endl;

    branch.viewBranch();
    branch.displayBranchDetails();

    return 0;
}