SMARTBANK MANAGEMENT SYSTEM

SmartBank is a C++ banking system that manages customers, branches, accounts, loans, and transactions using a MySQL database. The project follows object-oriented programming concepts and provides a menu-driven console application for a bank management workflow.

PROJECT OVERVIEW

This system allows users to:
- Add, view, search, update, and delete customer records
- View branch information and branch details
- Create and manage bank accounts
- Handle Savings and Current account operations
- Apply for and track loans
- Record deposits and withdrawals
- View transaction history for an account

FEATURES

Customer Management
- Add new customers
- View all customers
- Search a customer by ID
- Update customer details
- Delete customer records

Branch Management
- View all branches
- Search by branch ID or branch name
- Display branch details including city and IFSC code

Account Management
- Add account records
- View account records
- Search account information
- Deposit and withdraw balance

Savings and Current Accounts
- Savings account support with interest rate
- Current account support with overdraft limit
- Base Account class with inherited SavingsAccount and CurrentAccount classes

Loan Management
- Apply for loans
- View loan information
- Search customer loans
- Update loan status
- Calculate loan-related interest values

Transaction Management
- Deposit money into accounts
- Withdraw money from accounts
- Save transactions in the database
- Display transaction history for any account

TECH STACK

- Programming Language: C++
- Database: MySQL
- Database Access: MySQL C API (mysql.h)
- Design Pattern: Object-Oriented Programming (OOP)

PROJECT STRUCTURE

SmartBank/
├── include/
│   ├── Account.h
│   ├── Branch.h
│   ├── CurrentAccount.h
│   ├── Customer.h
│   ├── Database.h
│   ├── Loan.h
│   ├── SavingAccount.h
│   ├── Transaction.h
│   └── TransactionRepository.h
├── src/
│   ├── Account.cpp
│   ├── Branch.cpp
│   ├── CurrentAccount.cpp
│   ├── Customer.cpp
│   ├── Database.cpp
│   ├── Loan.cpp
│   ├── main.cpp
│   ├── SavingAccount.cpp
│   ├── Transaction.cpp
│   └── TransactionRepository.cpp
├── tests/
│   ├── AccountTest.cpp
│   ├── BranchTest.cpp
│   ├── CurrentAccountTest.cpp
│   ├── CustomerTest.cpp
│   ├── databasetest.cpp
│   ├── LoanTest.cpp
│   └── SavingAccountTest.cpp
├── smartbankdatabase.sql
├── README_Akshara.txt
├── build/
└── README.md (optional if you want a Markdown version)

DATABASE DESIGN

Main database tables are:
- customer
- branches
- accounts
- savingaccount
- currentaccount
- loans
- transactions

Examples of fields include:
- customer: customer_id, Firstname, Lastname, Phoneno, Email, DOB, Address, Gender
- branches: branch_id, branch_name, city, IFSC_code
- accounts: account_no, customer_id, Account_type, balance, opening_date, branch_id
- savingaccount: account_no, Interest_Rate
- currentaccount: account_no, overdraft_limit
- loans: loan_id, customer_id, loan_type, loan_amount, interest_rate, loan_date, loan_status
- transactions: transaction_id, account_no, transaction_type, amount, transaction_date

PREREQUISITES

Before running the project, make sure you have:
- MySQL Server installed and running
- MySQL development libraries available
- A C++ compiler such as g++ or MSVC
- A database named smartbank created in MySQL

SETUP INSTRUCTIONS

1. Open MySQL and create the database.
2. Import the SQL file named smartbankdatabase.sql.
3. Ensure the MySQL connection details in the project are correct.
4. Compile the C++ source files.
5. Run the executable.

BUILDING THE PROJECT

Typical command:

g++ -std=c++17 -Iinclude src/*.cpp -o smartbank -lmysqlclient

If using Windows, configure the MySQL include and library paths based on your environment.

RUNNING THE APPLICATION

After compilation, run the program with:

./smartbank

The program will display a menu-driven console interface where you can manage banking operations.

SAMPLE DATA

The database includes sample records for:
- Customer details
- Branches in Pune, Mumbai, and Nashik
- Savings and current accounts
- Loan records
- Transaction history

Example values present in the database:
- Savings interest rate: 4.50%
- Current overdraft limit: 50000.00

NOTES

- The project stores all major banking data in a MySQL database.
- It demonstrates how C++ OOP classes can interact with a database.
- The design is suitable for learning database integration and banking system operations.

AUTHOR

SmartBank Project
