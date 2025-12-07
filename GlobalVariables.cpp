#include "GlobalVariables.h"

Account accounts[5000];
int accountCount = 0;
int MAX_ACCOUNTS = 8000;

Account archivedAccounts[2000];
int archivedCount = 0;
int MAX_ARCHIVED = 4000;

Employee employees[1000];
int employeeCount = 0;
int MAX_EMPLOYEES = 2000;

Queue QueueLoanRequests;

List_SLL completed_loans;

std::string branches[100];
int branchCount = 0;
