#include "CustomerManagerMeth.h"
#include "GlobalVariables.h"

#include <iostream>
using namespace std;
void createCustomerArray(Account customers[], int size) {
    for (int i = 0; i < size; ++i) {
        customers[i] = Account();
        customers[i].loans = createList_DL();
        customers[i].PermenantTransaction = createList_SLT();
        customers[i].dailyTransactions = CreateStack();
    }
}

int Withdraw(Account& account, double withdrawAmount) {
    if (withdrawAmount > account.balance) {
        cout << "Sorry, you don't have enough to withdraw\n";
        return 1;
    }
    account.balance -= withdrawAmount;
    cout << "Withdraw successful\n";
    return 0;
}

int Deposit(Account& account, double depositAmount) {
    account.balance += depositAmount;
    cout << "Your deposit is successful\n";
    return 0;
}


int ViewLoans(const Account customers[], int customerCount, string accountNumber) {
    int idx = -1;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accountNumber == accountNumber) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Customer not found.\n";
        return 1;
    }
    const List_DL& loans = customers[idx].loans;
    if (loans.size_DL == 0) {
        cout << "You have no loans at the moment.\n";
        return 1;
    }
    Node_DL* current = loans.head_DL;
    while (current != nullptr) {
        const Loan& ln = current->data_DL;
        cout << "Loan ID: " << ln.loanID << "\n";
        cout << "Amount: " << ln.amount << "\n";
        cout << "Type: " << ln.loanType << "\n";
        cout << "Status: " << ln.status << "\n";
        cout << "------------------------\n";
        current = current->next_DL;
    }
    return 0;
}

int SubmitLoanRequest(Loan L, Queue* QueueLoanRequest) {
    Node_Q* appliedloan = CreateNode_Q(L);
    if (!appliedloan) {
        cout << "Memory error — please contact your agency\n";
        return 0;
    }
    if (IsEmpty_Q(*QueueLoanRequest)) {
        QueueLoanRequest->front_Q = appliedloan;
        QueueLoanRequest->tail_Q = appliedloan;
    }
    else {
        QueueLoanRequest->tail_Q->next_Q = appliedloan;
        QueueLoanRequest->tail_Q = appliedloan;
    }
    return 1;
}

int ViewTransactions(const Account customers[], int customerCount, string accountNumber) {
    int idx = -1;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accountNumber == accountNumber) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Customer not found.\n";
        return 1;
    }
    Stack* transactions = customers[idx].dailyTransactions;
    if (!transactions || IsStackEmpty(*transactions)) {
        cout << "No transactions available.\n";
        return 1;
    }
    int topIndex = transactions->Top;
    if (topIndex == 0) {
        cout << "No transactions available.\n";
        return 1;
    }
    for (int i = topIndex - 1; i >= 0; --i) {
        const Transaction& t = transactions->element[i];
        cout << "Transaction ID: " << t.transactionID << "\n";
        cout << "Account Number: " << t.accountNumber << "\n";
        cout << "Type: " << t.type << "\n";
        cout << "Amount: " << t.amount << "\n";
        cout << "Date: " << t.date << "\n";
        cout << "------------------------\n";
    }
    return 0;
}

int undoTransaction(Account& account) {
    Stack* transactions = account.dailyTransactions;
    if (!transactions || IsStackEmpty(*transactions)) {
        cout << "No transactions to undo.\n";
        return 1;
    }
    Transaction lastTransaction = Pop(transactions);
    if (lastTransaction.type == "deposit") {
        account.balance -= lastTransaction.amount;
    }
    else if (lastTransaction.type == "withdraw" || lastTransaction.type == "withdrawal") {
        account.balance += lastTransaction.amount;
    }
    cout << "Last transaction undone successfully.\n";
    return 0;
}
void ViewBalence(Account& acc) {
    cout<<"your Balence is : "<<acc.balance<<"TDN\n";
}


