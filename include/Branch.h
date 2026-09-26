#ifndef BRANCH_H
#define BRANCH_H

#include <string>

class Database;

class Branch
{
private:
    int branch_id;
    std::string branch_name;
    std::string city;
    std::string IFSC_code;

    Database* database;

public:
    explicit Branch(Database* db = nullptr);

    void viewBranch();
    void searchBranch();
    void displayBranchDetails();

    int getBranchId();
};

#endif