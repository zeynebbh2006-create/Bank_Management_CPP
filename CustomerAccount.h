#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H
#include <string>
#include "DoublyListLoansMeth.h"
#include "SinglyListPermenantTransactionMeth.h"
#include "SinglyListCompletedLoansMeth.h"
#include "StackDailyTransactionMeth.h"
#include "Loan.h"
using namespace std;
struct Account {
    string accountNumber = "";
    string password = "";
    string accountType = "";
    string IBAN = "";
    string branchCode = "";
    string holderName = "";
    string openingDate = "";
    string status = "active";
    double balance = 0.0;
    List_SLT PermenantTransaction = {};
    Stack* dailyTransactions = {};
    List_DL loans = {};
};

#endif