#include "../include/Database.h"
#include "../include/Transaction.h"
#include "../include/TransactionRepository.h"
#include "../include/Customer.h"
#include "../include/Branch.h"
#include "../include/Loan.h"
#include "../include/Account.h"
#include "../include/SavingAccount.h"
#include "../include/CurrentAccount.h"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int generateTransactionId(Database& db)
{
    MYSQL* connection = db.getConnection();

    if (connection == nullptr)
    {
        return 0;
    }

    if (mysql_query(
            connection,
            "SELECT COALESCE(MAX(transaction_id), 0) + 1 FROM transactions") != 0)
    {
        std::cout << "Could not generate transaction ID: "
                  << mysql_error(connection) << std::endl;

        return 0;
    }

    MYSQL_RES* result = mysql_store_result(connection);

    if (result == nullptr)
    {
        return 0;
    }

    MYSQL_ROW row = mysql_fetch_row(result);

    int id = 0;

    if (row != nullptr)
    {
        id = std::stoi(row[0]);
    }

    mysql_free_result(result);

    return id;
}

void transactionMenu(Database& db, TransactionRepository& repository)
{
    int choice;

    do
    {
        cout << "\n========== TRANSACTION MENU ==========\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Transaction History\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            long long accountNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accountNo;

            cout << "Enter Deposit Amount: ";
            cin >> amount;

            if (db.deposit(accountNo, amount))
            {
                Transaction transaction;

                transaction.setTransactionId(generateTransactionId(db));
                transaction.setAccountNo(accountNo);
                transaction.setAmount(amount);
                transaction.setTransactionType("Deposit");

                // MySQL will use the current date/time in the database.
   

                if (!repository.addTransaction(transaction))
                {
                    cout << "Warning: Balance updated, but transaction "
                         << "record could not be added.\n";
                }
            }
        }
        else if (choice == 2)
        {
            long long accountNo;
            double amount;

            cout << "Enter Account Number: ";
            cin >> accountNo;

            cout << "Enter Withdrawal Amount: ";
            cin >> amount;

            if (db.withdraw(accountNo, amount))
            {
                Transaction transaction;

               transaction.setTransactionId(generateTransactionId(db));
                transaction.setAccountNo(accountNo);
                transaction.setAmount(amount);
                transaction.setTransactionType("Withdrawal");

                

                if (!repository.addTransaction(transaction))
                {
                    cout << "Warning: Balance updated, but transaction "
                         << "record could not be added.\n";
                }
            }
        }
        else if (choice == 3)
        {
            long long accountNo;

            cout << "Enter Account Number: ";
            cin >> accountNo;

            repository.displayTransactions(accountNo);
        }
        else if (choice == 4)
        {
            cout << "Returning to main menu...\n";
        }
        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);
}


int main()
{
    Database db;

    if (!db.connect())
    {
        cout << "Database connection failed." << endl;
        return 1;
    }

    TransactionRepository repository(&db);

    int choice;

    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "          SMARTBANK SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Customer Management\n";
        cout << "2. Branch Management\n";
        cout << "3. Account Management\n";
        cout << "4. Saving Account\n";
        cout << "5. Current Account\n";
        cout << "6. Loan Management\n";
        cout << "7. Transactions\n";
        cout << "8. Exit\n";
        cout << "========================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Customer customer;

            int customerChoice;

            cout << "\n----- CUSTOMER MENU -----\n";
            cout << "1. Add Customer\n";
            cout << "2. View Customer\n";
            cout << "3. Search Customer\n";
            cout << "4. Update Customer\n";
            cout << "5. Delete Customer\n";
            cout << "Enter choice: ";
            cin >> customerChoice;

            switch (customerChoice)
            {
            case 1:
                customer.addCustomer();
                break;

            case 2:
                customer.viewCustomer();
                break;

            case 3:
                customer.searchCustomer();
                break;

            case 4:
                customer.updateCustomer();
                break;

            case 5:
                customer.deleteCustomer();
                break;

            default:
                cout << "Invalid choice.\n";
            }

            break;
        }

        case 2:
        {
            Branch branch;

            int branchChoice;

            cout << "\n----- BRANCH MENU -----\n";
            cout << "1. View Branch\n";
            cout << "2. Search Branch\n";
            cout << "3. Display Branch Details\n";
            cout << "Enter choice: ";
            cin >> branchChoice;

            switch (branchChoice)
            {
            case 1:
                branch.viewBranch();
                break;

            case 2:
                branch.searchBranch();
                break;

            case 3:
                branch.displayBranchDetails();
                break;

            default:
                cout << "Invalid choice.\n";
            }

            break;
        }

        case 3:
        {
            Account account;

            int accountChoice;

            cout << "\n----- ACCOUNT MENU -----\n";
            cout << "1. Add Account\n";
            cout << "2. View Account\n";
            cout << "3. Search Account\n";
            cout << "Enter choice: ";
            cin >> accountChoice;

            switch (accountChoice)
            {
            case 1:
                account.addAccount();
                break;

            case 2:
                account.viewAccount();
                break;

            case 3:
                account.searchAccount();
                break;

            default:
                cout << "Invalid choice.\n";
            }

            break;
        }

        case 4:
        {
            SavingAccount saving;

            cout << "\n----- SAVING ACCOUNT -----\n";
            saving.viewSavingAccount();
            break;
        }

        case 5:
        {
            CurrentAccount current;

            cout << "\n----- CURRENT ACCOUNT -----\n";
            current.viewCurrentAccount();
            break;
        }

        case 6:
        {
            Loan loan;

            int loanChoice;

            cout << "\n----- LOAN MENU -----\n";
            cout << "1. Apply Loan\n";
            cout << "2. View Loan\n";
            cout << "3. Search Customer Loans\n";
            cout << "4. Update Loan Status\n";
            cout << "5. Calculate Interest\n";
            cout << "Enter choice: ";
            cin >> loanChoice;

            switch (loanChoice)
            {
            case 1:
                loan.applyLoan();
                break;

            case 2:
                loan.viewLoan();
                break;

            case 3:
                loan.searchCustomerLoans();
                break;

            case 4:
                loan.updateLoanStatus();
                break;

            case 5:
                loan.calculateInterest();
                break;

            default:
                cout << "Invalid choice.\n";
            }

            break;
        }

        case 7:
            transactionMenu(db, repository);
            break;

        case 8:
            cout << "Thank you for using SmartBank.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    db.disconnect();

    return 0;
}