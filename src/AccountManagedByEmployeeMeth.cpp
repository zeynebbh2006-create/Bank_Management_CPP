#include "AccountManagedByEmployeeMeth.h"
#include "GlobalVariables.h"
#include <iostream>

using namespace std;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Error: Maximum number of accounts reached!" << endl;
        return;
    }
    Account newAcc;
    cout << "\n=== ADD NEW CUSTOMER ACCOUNT ===" << endl;
    newAcc.accountNumber = generateAccountNumber();
    cout << "Generated Account Number: " << newAcc.accountNumber << endl;
    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, newAcc.holderName);
    cout << "Enter Account password : ";
    getline(cin, newAcc.password);
    cout << "Enter Account Type (Savings/Current/Business): ";
    getline(cin, newAcc.accountType);
    cout << "Enter Branch Code: ";
    getline(cin, newAcc.branchCode);
    cout << "Enter Opening Date (DD/MM/YYYY): ";
    getline(cin, newAcc.openingDate);
    cout << "Enter Initial Balance (TND): ";
    cin >> newAcc.balance;
    newAcc.IBAN = generateIBAN(newAcc.accountNumber);
    newAcc.status = "active";
    newAcc.loans = createList_DL();;
    newAcc.PermenantTransaction = createList_SLT();
    newAcc.dailyTransactions = CreateStack();
    accounts[accountCount++] = newAcc;
    cout << "\nAccount created successfully!" << endl;
    cout << "IBAN: " << newAcc.IBAN << endl;
}

void displayAllAccounts() {
    if (accountCount == 0) {
        cout << "No accounts to display." << endl;
        return;
    }
    cout << "\n=== ALL CUSTOMER ACCOUNTS ===" << endl;
    cout << "Total Accounts: " << accountCount << endl;
    for (int i = 0; i < accountCount; i++) {
        displayAccount(accounts[i]);
    }
}

void changeAccountStatus() {
    string accountNumber, newStatus;
    int choice;
    cout << "\n=== CHANGE ACCOUNT STATUS ===" << endl;
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    int index = findAccountIndex(accountNumber);
    if (index == -1) {
        cout << "Error: Account not found!" << endl;
        return;
    }
    cout << "\nCurrent account:\n";
    displayAccount(accounts[index]);
    cout << "\nSelect new status:\n";
    cout << "1. Active\n";
    cout << "2. Inactive\n";
    cout << "3. Closed\n";
    cout << "Choice: ";
    cin >> choice;
    switch (choice) {
    case 1: newStatus = "active"; break;
    case 2: newStatus = "inactive"; break;
    case 3:
        newStatus = "closed";
        cout << "WARNING: Closed accounts will be archived!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }
    accounts[index].status = newStatus;
    cout << "\nAccount status changed to: " << newStatus << endl;
}

void archiveClosedAccounts() {
    int archivedInThisSession = 0;
    int i = 0;

    cout << "\n=== ARCHIVING CLOSED ACCOUNTS ===" << endl;

    while (i < accountCount) {
        if (accounts[i].status == "closed") {

            if (archivedCount >= MAX_ARCHIVED) {
                cout << "Warning: Archive is full!" << endl;
                break;
            }

            archivedAccounts[archivedCount++] = accounts[i];
            archivedInThisSession++;

            cout << "Archived: " << accounts[i].accountNumber
                << " - " << accounts[i].holderName << endl;

            for (int j = i; j < accountCount - 1; j++) {
                accounts[j] = accounts[j + 1];
            }

            accountCount--;
        }
        else {
            i++;
        }
    }

    cout << "\nTotal accounts archived: " << archivedInThisSession << endl;
    cout << "Active accounts remaining: " << accountCount << endl;
}

void displayAccount(const Account& acc) {
    cout << "========================================" << endl;
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "IBAN: " << acc.IBAN << endl;
    cout << "Holder Name: " << acc.holderName << endl;
    cout << "Type: " << acc.accountType << endl;
    cout << "Branch: " << acc.branchCode << endl;
    cout << "Opening Date: " << acc.openingDate << endl;
    cout << "Status: " << acc.status << endl;
    cout << "Balance: " << acc.balance << " TND" << endl;
    cout << "========================================" << endl;
}

string generateAccountNumber() {
    static int counter = 1000;

    string accNum;
    do {
        accNum = "ACC" + to_string(counter++);
    } while (!isAccountNumberUnique(accNum));

    return accNum;
}

string generateIBAN(string accountNumber) {
    return "TN59" + accountNumber + "000001";
}

bool isAccountNumberUnique(string accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber)
            return false;
    }
    return true;
}

int findAccountIndex(string accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber)
            return i;
    }
    return -1;
}

int displayLoansForCustomer(Account& customer) {
    List_DL loans = customer.loans;
    if (!&loans || loans.size_DL == 0) {
        cout << "No loans for account #" << customer.accountNumber << ".\n";
        return 1;
    }
    cout << "\n=== Loans for Account #" << customer.accountNumber << " ===\n";
    Node_DL* current = loans.head_DL;
    while (current) {
        Loan l = current->data_DL;

        cout << "Loan ID: " << l.loanID << "\n"
            << "Type: " << l.loanType << "\n"
            << "Amount: " << l.amount << "\n"
            << "Rate: " << l.rate << "%\n"
            << "Paid: " << l.paid << "\n"
            << "Balance: " << l.balance << "\n"
            << "Start: " << l.startDate << " | End: " << l.endDate << "\n"
            << "Status: " << l.status << "\n"
            << "------------------------------\n";
        current = current->next_DL;
    }
    return 0;
}

bool changeLoanStatus(Account customer, int loanID, const string& newStatus) {
    List_DL loans = customer.loans;
    if (!&loans || loans.size_DL == 0) {
        cout << "No loans for this customer.\n";
        return false;
    }
    Node_DL* current = loans.head_DL;
    while (current) {
        if (current->data_DL.loanID == loanID) {
            current->data_DL.status = newStatus;
            cout << "Loan " << loanID << " status updated to '" << newStatus << "'.\n";
            return true;
        }
        current = current->next_DL;
    }
    cout << "Loan not found.\n";
    return false;
}

void removeCompletedLoans(Account& customer) {
    Node_DL* current = customer.loans.head_DL;
    int pos = 1;
    while (current) {
        Node_DL* next = current->next_DL;
        if (current->data_DL.status == "completed") {
            Loan completedLoan = current->data_DL;
            removeAt_DL(&customer.loans, pos);
            insert_SLL(&completed_loans, completedLoan, completed_loans.size_SLL);
            cout << "Archived completed loan ID " << completedLoan.loanID << " into completed_loans.\n";
        }
        else {
            pos++;
        }
        current = next;
    }
}

void processLoanRequestsFIFO(Queue* loanQueue, Account accounts[], int numAccounts) {
    if (IsEmpty_Q(*loanQueue)) {
        cout << "No pending loan requests.\n";
        return;
    }
    DisplayQueue_Q(*loanQueue);
    cout << "\nProcess next loan request? (1=Approve, 2=Reject, 0=Skip): ";
    int decision;
    cin >> decision;
    if (decision == 0) return;
    Loan loan = Dequeue_Q(loanQueue);
    if (decision == 1) {
        loan.status = "active";
        int accountIndex = -1;
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].accountNumber == loan.accountNumber) {
                accountIndex = i;
                break;
            }
        }
        if (accountIndex != -1) {
            insert_DL(&accounts[accountIndex].loans, loan, accounts[accountIndex].loans.size_DL + 1);
            cout << "Loan " << loan.loanID << " approved and added.\n";
        }
        else {
            cout << "Account not found.\n";
        }
    }
    else if (decision == 2) {
        loan.status = "rejected";
        cout << "Loan " << loan.loanID << " rejected.\n";
    }
    else {
        cout << "Invalid decision.\n";
    }
}
void addLoanToList(Node_DL* head, const Loan& loan) {
    Node_DL* newNode = createNode_DL(loan); // helper from LoanNode_meth
    if (!head) {
        head = newNode;
    }
    else {
        Node_DL* curr = head;
        while (curr->next_DL) {
            curr = curr->next_DL;
        }
        curr->next_DL = newNode;
    }
    cout << "Loan " << loan.loanID << " added to loan list.\n";
}
void addDailyTransaction(Account& acc, const Transaction& t) {
    int success = Push(acc.dailyTransactions, t);
    if (success)
        cout << "Transaction added.\n";
    else
        cout << "Failed to add transaction.\n";
}

void undoLastTransaction(Account& acc) {
    if (IsStackEmpty(*acc.dailyTransactions)) {
        cout << "No transaction to undo.\n";
        return;
    }

    Transaction t = Pop(acc.dailyTransactions);

    if (t.type == "deposit")
        acc.balance -= t.amount;
    else if (t.type == "withdraw")
        acc.balance += t.amount;

    cout << "Transaction undone.\n";
}

void finalizeDay(Account& acc) {
    if (IsStackEmpty(*acc.dailyTransactions)) {
        cout << "No transactions to finalize.\n";
        return;
    }
    Stack* temp = CreateStack();
    while (!IsStackEmpty(*acc.dailyTransactions)) {
        Push(temp, Pop(*&acc.dailyTransactions));
    }
    while (!IsStackEmpty(*temp)) {
        Transaction t = Pop(temp);
        insert_SLT(&acc.PermenantTransaction, t, acc.PermenantTransaction.size_SLT + 1);
    }
    cout << "Day finalized. Transactions added to permanent history.\n";
}

void displayTransactionHistory(const List_SLT& L) {
    displayList_SLT(L);
}
