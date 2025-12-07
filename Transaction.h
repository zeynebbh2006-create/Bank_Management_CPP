#ifndef STRUCTTRANSACTION_H
#define STRUCTTRANSACTION_H
#include <string>
using namespace std;
struct Transaction {
    string transactionID = "";
    string accountNumber = "";
    string type = "";                      
    double amount = 0.0;
    string date = "";
};
#endif