#include "CustomerManagerMeth.h"               
#include "StackDailyTransactionMeth.h"
#include "SinglyListPermenantTransactionMeth.h"
#include "GlobalVariables.h"
using namespace std;

int CustomerMenu() {

    cout << "\n========== CUSTOMER PORTAL ==========\n";
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
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].password == password) {
                found = true;
                idx = i;
                break;
            }
        }

        if (!found) {
            cout << " Incorrect password. Access denied.\n";
            return 0;
        }

        cout << " Login successful. Welcome "
            << accounts[idx].holderName << "\n";
    }
    else {
        return 0;
    }
    while (true) {

        cout << "\n====== CUSTOMER ACTIONS ======\n";
        cout << "1. View My Loans\n";
        cout << "2. Submit a Loan Request\n";
        cout << "3. View Transaction History\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Undo Last Transaction\n";
        cout << "7. View My Balence\n";
        cout << "0. Exit Menu\n";
        cout << "Choose an option: ";
        char choice;
        cin >> choice;

        if (choice == '0')
            break;

        string accNum;
        int idx = -1;

        cout << "\nEnter your Account Number: ";
        cin >> accNum;

        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].accountNumber == accNum) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << " Account not found.\n";
            continue;
        }

        Account& acc = accounts[idx];

        switch (choice) {

        case '1':
            ViewLoans(accounts, accountCount, accNum);
            break;

        case '2': {
            Loan L;
            cout << "Enter Loan ID: ";
            cin >> L.loanID;
            cout << "Loan Type (car/home/business/student): ";
            cin >> L.loanType;
            cout << "Amount: ";
            cin >> L.amount;
            cout << "Rate: ";
            cin >> L.rate;
            cout << "Start Date: ";
            cin >> L.startDate;
            cout << "End Date: ";
            cin >> L.endDate;

            L.accountNumber = acc.accountNumber;
            L.status = "pending";

            int success = SubmitLoanRequest(L, &QueueLoanRequests);
            if (success == 0)
                cout << " Loan request submitted successfully.\n";
            else
                cout << " Failed to submit loan request.\n";
            break;
        }

        case '3':
            ViewTransactions(accounts, accountCount, accNum);
            break;

        case '4': {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            Deposit(acc, amount);
            cout << " Deposit successful.\n";
            break;
        }

        case '5': {
            double amount;
            cout << "Enter withdraw amount: ";
            cin >> amount;
            Withdraw(acc, amount);
            break;
        }

        case '6':
            undoTransaction(acc);
            break;
        case '7':
            ViewBalence(acc);
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    cout << "Exiting customer portal...\n";
    return 0;
}
