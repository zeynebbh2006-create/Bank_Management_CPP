#ifndef ACCOUNTMANAGEDBYEMPLOYEEMETH_H
#define ACCOUNTMANAGEDBYEMPLOYEEMETH_H
#include "QueueLoansRequestMeth.h"
#include "DoublyListLoansMeth.h"
#include "SinglyListPermenantTransactionMeth.h"
#include "SinglyListCompletedLoansMeth.h"
#include "StackDailyTransactionMeth.h"
#include "CustomerAccount.h"
#include <iostream>
void addAccount();
void displayAllAccounts();
void changeAccountStatus();
void archiveClosedAccounts();
bool isAccountNumberUnique(string accountNumber);
int findAccountIndex(string accountNumber);
void displayAccount(const Account& acc);
string generateAccountNumber();
string generateIBAN(string accountNumber);
int displayLoansForCustomer(Account& customer);
bool changeLoanStatus(Account customer, int loanID, const string& newStatus);
void removeCompletedLoans(Account& customer);
void processLoanRequestsFIFO(Queue* loanQueue, Account accounts[], int numAccounts);
void addLoanToList(Node_DL* head, const Loan& loan);
void addDailyTransaction(Account& acc, const Transaction& t);
void undoLastTransaction(Account& acc);
void finalizeDay(Account& acc);
void displayTransactionHistory(const List_SLT& L);
#endif;