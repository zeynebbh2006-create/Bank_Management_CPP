#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include "CustomerAccount.h"
#include "DoublyListLoansMeth.h"
#include "QueueLoansRequestMeth.h"
using namespace std;
void createCustomerArray(Account customers[], int size);
int Withdraw(Account& customer, double withdrawamount);
int Deposit(Account& customer, double depositAmount);
int ViewLoans(const Account customers[], int customerCount, string accountNumber);
int SubmitLoanRequest(Loan L, Queue* QueueLoanRequest);
int ViewTransactions(const Account customers[], int customerCount, string accountNumber);
int undoTransaction(Account& customer);
void ViewBalence(Account& acc);

#endif