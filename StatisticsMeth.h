#ifndef STATISTICSMETH_H
#define STATISTICSMETH_H
#include "DoublyListLoans.h"
#include "EmployeeManagerMeth.h"
#include "CustomerAccount.h"
#include <string>
int CustomerLoansNbr(List_DL* L);
int TotalLoansNbr(Account customers[], int size);
void LoansByTypeNbr(Account customers[], int size);
void getLoansByStatus(Account customers[], int size);
bool RangeDate(const string& date, const string& start, const string& end);
int ActiveLoansInDateRange(const string& start, const string& end, Account accounts[], int size);
Account HighestLoans(int size, Account customers[]);
Account HighestBalance(Account customers[], int size);
Account LowestBalance(int size, Account customers[]);
int TotalEmployees(int employeeCount);
int getEmployeesPerBranch(Employee[], int employeeCount, string branchCode);
#endif
