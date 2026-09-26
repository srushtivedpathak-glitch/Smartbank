#include "Branch.h"
#include <iostream>

using namespace std;

// Constructor
Branch::Branch()
{
    branch_id = 1;
    branch_name = "SMARTBANK Pune";
    city = "Pune";
    IFSC_code = "SMRT000001";
}

// View Branch
void Branch::viewBranch()
{
    cout << "\n----- Branch Details -----" << endl;
    cout << "Branch ID   : " << branch_id << endl;
    cout << "Branch Name : " << branch_name << endl;
    cout << "City        : " << city << endl;
    cout << "IFSC Code   : " << IFSC_code << endl;
}

// Search Branch
void Branch::searchBranch()
{
    int id;

    cout << "Enter Branch ID to search: ";
    cin >> id;

    if (id == branch_id)
    {
        cout << "\nBranch found!" << endl;
        viewBranch();
    }
    else
    {
        cout << "\nBranch not found!" << endl;
    }
}

// Display Branch Details
void Branch::displayBranchDetails()
{
    cout << "\n----- Branch Information -----" << endl;
    cout << "Branch ID   : " << branch_id << endl;
    cout << "Branch Name : " << branch_name << endl;
    cout << "City        : " << city << endl;
    cout << "IFSC Code   : " << IFSC_code << endl;
}

// Get Branch ID
int Branch::getBranchId()
{
    return branch_id;
}