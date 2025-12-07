#ifndef LOAN_H
#define LOAN_H 
#include <iostream>
#include <string>
using namespace std;
struct Loan {
    int loanID = 0;
    string accountNumber = "";
    string loanType = "";
    double amount = 0.0;
    double rate = 0.0;
    int paid = 0;
    string startDate = "";
    string endDate = "";
    string status = "";
    int balance = 0;
};
#endif