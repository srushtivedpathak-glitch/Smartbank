SMARTBANK - AKSHARA PART

This module follows the same simple OOP style used by the existing
Customer, Branch, Loan and Transaction classes.

Files:
include/
    Account.h
    SavingAccount.h
    CurrentAccount.h

src/
    Account.cpp
    SavingAccount.cpp
    CurrentAccount.cpp

tests/
    AccountTest.cpp
    SavingAccountTest.cpp
    CurrentAccountTest.cpp

DATABASE MAPPING

Account:
accounts
- account_no
- customer_id
- Account_type
- balance
- opening_date
- branch_id

SavingAccount:
savingaccount
- account_no
- Interest_Rate

CurrentAccount:
currentaccount
- account_no
- overdraft_limit

OOP RELATIONSHIP

Account
  |
  +-- SavingAccount
  |
  +-- CurrentAccount

The Account class contains common account information and basic
deposit/withdraw operations. SavingAccount and CurrentAccount inherit
the common Account data and add account-specific functionality.

NOTE:
The existing project uses Database/Repository code for MySQL operations.
These classes are kept as the application/OOP classes and do not create
a second MySQL connection.

SAMPLE DATABASE VALUES:
Savings interest rate = 4.50%
Current overdraft limit = 50000.00
