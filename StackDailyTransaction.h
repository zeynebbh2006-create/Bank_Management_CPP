#ifndef STACKDAILYTRANSACTION_H
#define STACKDAILYTRANSACTION_H
#include "Transaction.h"
using namespace std;
constexpr int Max = 100;
struct Stack {
    Transaction element[Max];
    int Top;
};
#endif