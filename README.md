# SmartBank Management System

SmartBank is a C++-based banking system that connects a desktop application to a MySQL database for managing customers, branches, accounts, loans, and transactions. The application follows object-oriented programming principles and uses the MySQL C API for database communication.

## System Architecture

```text
┌──────────────────────────────┐
│       TIER 1                 │
│                              │
│   C++ SmartBank Application  │
│   - User Interface           │
│   - Business Logic           │
│   - MySQL C API              │
└──────────────┬───────────────┘
               │
               │ SQL Queries
               │ / Results
               ▼
┌──────────────────────────────┐
│       TIER 2                 │
│                              │
│       MySQL Server           │
│       SmartBank Database     │
│                              │
│   - Store data               │
│   - Execute SQL              │
│   - Enforce constraints      │
└──────────────────────────────┘
```

## Overview

This system helps manage:
- Customer registration and profile handling
- Branch information and searching
- Account creation and management
- Savings and current account operations
- Loan applications and tracking
- Deposits, withdrawals, and transaction history

## Features

### Customer Management
- Add a new customer
- View customer details
- Search customers
- Update customer information
- Delete customer records

### Branch Management
- View branch records
- Search branches by ID or name
- Display city and IFSC information

### Account Management
- Add accounts
- View account details
- Search accounts
- Process deposits and withdrawals

### Savings and Current Accounts
- Savings account handling with interest rate support
- Current account handling with overdraft limit support
- Inheritance-based design using a base `Account` class

### Loan Management
- Apply for loans
- View loan information
- Search customer loans
- Update loan status
- Calculate interest-related values

### Transaction Management
- Record deposits
- Record withdrawals
- Store transaction data in the database
- Display transaction history for a specific account

## Technologies & Tools

### Programming Language
- C++

### Compiler
- G++ 16.2.0 (MSYS2 UCRT64)

### Database
- MySQL Server 8.0.46

### SQL / Connectivity
- MySQL C API
- MySQL client library (`libmysql`)
- `mysql.h`
- `libmysql.dll`

### Development & Version Control
- Visual Studio Code / IDE
- Git & GitHub

## C++ SmartBank Application Flow

```text
C++ SmartBank Application
                   │
                   │ MySQL C API
                   ▼
          MySQL Client Library
           (libmysql / DLL)
                   │
                   │ SQL Queries
                   ▼
             MySQL Server
                   │
                   ▼
             SmartBank DB
```

## Project Structure

```text
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
├── README.md
├── build/
└── .vscode/
```

## Database Design

The project uses a MySQL database named `smartbank` with the following main tables:
- `customer`
- `branches`
- `accounts`
- `savingaccount`
- `currentaccount`
- `loans`
- `transactions`

### Example fields
- `customer`: `customer_id`, `Firstname`, `Lastname`, `Phoneno`, `Email`, `DOB`, `Address`, `Gender`
- `branches`: `branch_id`, `branch_name`, `city`, `IFSC_code`
- `accounts`: `account_no`, `customer_id`, `Account_type`, `balance`, `opening_date`, `branch_id`
- `savingaccount`: `account_no`, `Interest_Rate`
- `currentaccount`: `account_no`, `overdraft_limit`
- `loans`: `loan_id`, `customer_id`, `loan_type`, `loan_amount`, `interest_rate`, `loan_date`, `loan_status`
- `transactions`: `transaction_id`, `account_no`, `transaction_type`, `amount`, `transaction_date`

## Prerequisites

Before running the project, ensure the following are installed:
- MySQL Server
- MySQL development libraries / connector
- C++ compiler such as `g++` or MSVC
- A MySQL database named `smartbank`

## Setup Instructions

1. Open MySQL and create the database if it does not exist.
2. Import the file `smartbankdatabase.sql` into MySQL.
3. Make sure the database connection details in the project are correctly configured.
4. Compile the C++ project.
5. Run the executable.

## Build

Typical build command:

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o smartbank -lmysqlclient
```

If you are using Windows, configure the MySQL include and library paths according to your environment.

## Run

```bash
./smartbank
```

The program will open a menu-based banking interface for using the system.

## Sample Data

The project includes sample records for:
- Customers
- Branches in Pune, Mumbai, and Nashik
- Savings and current accounts
- Loan records
- Transaction history

Example values:
- Savings interest rate: `4.50%`
- Current account overdraft limit: `50000.00`

## Notes

- Data is stored using a MySQL database.
- The project demonstrates database connectivity and object-oriented design in C++.
- It is suitable for learning banking system logic and MySQL integration.

## Author

SmartBank Project
