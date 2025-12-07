
#include "EmployeeManagerMeth.h"
#include "AccountManagedByEmployeeMeth.h"
#include "StatisticsInterface.h"
#include "EmployeeInterface.h"
#include "GlobalVariables.h"
using namespace std;

void EmployeeMenu() {
    cout << "\n========== EMPLOYEE PORTAL ==========\n";
    cout << "1. Login\n";
    cout << "2. Exit\n";
    cout << "Choose an option: ";
    char loginChoice;
    cin >> loginChoice;

    if (loginChoice == '1') {

        string password;
        cout << "Enter your password: ";
        cin >> password;

        bool found = false;
        int idx = -1;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].password == password) {
                found = true;
                idx = i;
                break;
            }
        }

        if (!found) {
            cout << " Incorrect password. Access denied.\n";
            return ;
        }

        cout << " Login successful. Welcome "
            << employees[idx].name << "\n";
    }
    else {
        return ;
    }
    char choice;
    do {
        cout << "\n=====================================\n";
        cout << "         EMPLOYEE MENU\n";
        cout << "=====================================\n";
        cout << "         1. Manage Accounts          \n";
        cout << "         2. Manage Loans             \n";
        cout << "         3. Manage Transactions      \n";
        cout << "         4. Employee Management      \n";
        cout << "         5. Statistics Menu          \n";
        cout << "         0. Logout                   \n";
        cout << "-------------------------------------\n";
        cout << "        Enter your choice:    ";
        cin >> choice;

        switch (choice) {
        case '1': {
            char sub;
            cout << "\n------ ACCOUNT MANAGEMENT ------\n";
            cout << "----------------------------------\n";
            cout << "       a. Add new account         \n";
            cout << "       b. Display all accounts    \n";
            cout << "       c. Change account status   \n";
            cout << "       d. Archive closed accounts \n";
            cout << "       f.Return back              \n";
            cout << "-----------------------------------\n";
            cout << "         Enter option:   ";
            cin >> sub;
            switch (sub) {
            case 'a': addAccount(); break;
            case 'b': displayAllAccounts(); break;
            case 'c': changeAccountStatus(); break;
            case 'd': archiveClosedAccounts(); break;
            case 'f': break;
            default: cout << "Invalid option.\n"; break;
            }
            break;
        }

        case '2': {
            char sub;
            cout << "\n------------- LOAN MANAGEMENT --------------\n";
            cout << "----------------------------------------------\n";
            cout << "         a. Show loans for a customer         \n";
            cout << "         b. Change loan status                \n";
            cout << "         c. Remove completed loans            \n";
            cout << "         d. Process loan requests (FIFO)      \n";
            cout << "----------------------------------------------\n";
            cout << "              Enter option:    ";
            cin >> sub;
            switch (sub) {
            case 'a': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx != -1)
                    displayLoansForCustomer(accounts[idx]);
                else
                    cout << "Account not found.\n";
                break;
            }
            case 'b': {
                string accNum;
                int loanID;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx == -1) {
                    cout << "Account not found.\n";
                    break;
                }
                cout << "Enter loan ID: ";
                cin >> loanID;
                string newStatus;
                cout << "Enter new status: ";
                cin >> newStatus;
                changeLoanStatus(accounts[idx], loanID, newStatus);
                break;
            }
            case 'c': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx != -1)
                    removeCompletedLoans(accounts[idx]);
                else
                    cout << "Account not found.\n";
                break;
            }
            case 'd':
                processLoanRequestsFIFO(&QueueLoanRequests, accounts, accountCount);
                break;
            default:
                cout << "Invalid option.\n";
            }
            break;
        }

        case '3': {
            char sub;
            cout << "\n------ TRANSACTION MANAGEMENT ------\n";
            cout << "--------------------------------------\n";
            cout << "      a. Add daily transaction        \n";
            cout << "      b. Undo last transaction        \n";
            cout << "      c. Finalize day                 \n";
            cout << "      d. View transaction history     \n";
            cout << "--------------------------------------\n";
            cout << "          Enter option:   ";
            cin >> sub;

            switch (sub) {
            case 'a': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx == -1) {
                    cout << "Account not found.\n";
                    break;
                }
                Transaction t;
                cout << "Enter transaction type: ";
                cin >> t.type;
                cout << "Enter amount: ";
                cin >> t.amount;
                addDailyTransaction(accounts[idx], t);
                break;
            }
            case 'b': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx != -1)
                    undoLastTransaction(accounts[idx]);
                else
                    cout << "Account not found.\n";
                break;
            }
            case 'c': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx != -1)
                    finalizeDay(accounts[idx]);
                else
                    cout << "Account not found.\n";
                break;
            }
            case 'd': {
                string accNum;
                cout << "Enter account number: ";
                cin >> accNum;
                int idx = findAccountIndex(accNum);
                if (idx != -1)
                    displayTransactionHistory(accounts[idx].PermenantTransaction);
                else
                    cout << "Account not found.\n";
                break;
            }
            default:
                cout << "Invalid option.\n";
            }
            break;
        }

        case '4': {
            char sub;
            cout << "\n------------------ EMPLOYEE MANAGEMENT ------------------\n";
            cout << "-----------------------------------------------------------\n";
            cout << "                a. Add employee                            \n";
            cout << "                b. Delete employee                         \n";
            cout << "                c. Modify employee                         \n";
            cout << "                d. Display by branch                       \n";
            cout << "                e. Display earliest & latest hired         \n";
            cout << "                f. Display by last name                    \n";
            cout << "-----------------------------------------------------------\n";
            cout << "                     Enter option:     ";
            cin >> sub;
            switch (sub) {
            case 'a': addEmployee(); break;
            case 'b': deleteEmployee(); break;
            case 'c': modifyEmployee(); break;
            case 'd': displayEmployeesByBranch(); break;
            case 'e': displayEarliestAndLatestHired(); break;
            case 'f': displayEmployeesByLastName(); break;
            default: cout << "Invalid option.\n";
            }
            break;
        }

        case '5': {
            statisticsMenu();
            break;
        }

        case '0':
            cout << "Logged out.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != '0');

    return;
}