#include "StatisticsMeth.h"
#include "GlobalVariables.h"
#include <iostream>
#include <string>
using namespace std;

int CustomerLoansNbr(List_DL* L) {
    return (L->size_DL);
}

int TotalLoansNbr(Account accounts[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += CustomerLoansNbr(&accounts[i].loans);
    }
    return total;
}

void LoansByTypeNbr(Account accounts[], int size) {
    int car = 0, home = 0, student = 0, business = 0;
    for (int i = 0; i < size; i++) {
        List_DL& loanList = accounts[i].loans;
        Node_DL* cur = loanList.head_DL;
        while (cur != nullptr) {
            const string& type = cur->data_DL.loanType;
            if (type == "car") ++car;
            else if (type == "home") ++home;
            else if (type == "student") ++student;
            else if (type == "business") ++business;
            cur = cur->next_DL;
        }
    }
    cout << "Car loans: " << car << endl;
    cout << "Home loans: " << home << endl;
    cout << "Student loans: " << student << endl;
    cout << "Business loans: " << business << endl;
}

void getLoansByStatus(Account accounts[], int size) {
    int active = 0, completed = 0, overdue = 0;
    for (int i = 0; i < size; i++) {
        List_DL& loanList = accounts[i].loans;
        Node_DL* cur = loanList.head_DL;
        while (cur != nullptr) {
            const string& st = cur->data_DL.status;
            if (st == "active") ++active;
            else if (st == "completed") ++completed;
            else if (st == "overdue") ++overdue;
            cur = cur->next_DL;
        }
    }
    cout << "Active loans: " << active << endl;
    cout << "Completed loans: " << completed << endl;
    cout << "Overdue loans: " << overdue << endl;
}

bool RangeDate(const string& date, const string& start, const string& end) {
    return date >= start && date <= end;
}

// Count active loans whose date is in range (uses loan startDate)
int ActiveLoansInDateRange(const string& start, const string& end, Account accounts[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        List_DL& loanList = accounts[i].loans;
        Node_DL* cur = loanList.head_DL;
        while (cur != nullptr) {
            if (cur->data_DL.status == "active" && RangeDate(cur->data_DL.startDate, start, end)) {
                ++count;
            }
            cur = cur->next_DL;
        }
    }
    return count;
}

Account HighestLoans(int size, Account accounts[]) {
    Account emptyAccount{};
    if (size == 0) return emptyAccount;

    int maxLoans = -1;
    Account result = emptyAccount;
    for (int i = 0; i < size; i++) {
        int n = CustomerLoansNbr(&accounts[i].loans);
        if (n > maxLoans) {
            maxLoans = n;
            result = accounts[i];
        }
    }
    return result;
}

// Return the Account with the highest balance
Account HighestBalance(Account accounts[], int size) {
    Account emptyAccount{};
    if (size == 0) return emptyAccount;

    Account richest = accounts[0];
    for (int i = 1; i < size; i++) {
        if (accounts[i].balance > richest.balance)
            richest = accounts[i];
    }
    return richest;
}

Account LowestBalance(int size, Account accounts[]) {
    Account emptyAccount{};
    if (size == 0) return emptyAccount;

    Account lowest = accounts[0];
    for (int i = 1; i < size; i++) {
        if (accounts[i].balance < lowest.balance)
            lowest = accounts[i];
    }
    return lowest;
}
int TotalEmployees(int employeeCount) {
    return employeeCount;
}

int getEmployeesPerBranch(Employee[], int employeeCount, string branchCode) {
    int count = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].branchCode == branchCode)
        {
            count++;
        }
    }
    return count;
}
