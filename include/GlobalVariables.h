#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include "CustomerAccount.h"
#include "QueueLoansRequestMeth.h"
#include "SinglyListCompletedLoans.h"
#include "Employee.h"

extern Account accounts[5000];
extern int accountCount;
extern int MAX_ACCOUNTS;

extern Account archivedAccounts[2000];
extern int archivedCount;
extern int MAX_ARCHIVED;

extern Employee employees[1000];
extern int employeeCount;
extern int MAX_EMPLOYEES;

extern Queue QueueLoanRequests;

extern List_SLL completed_loans;

extern std::string branches[100];
extern int branchCount;


#endif
