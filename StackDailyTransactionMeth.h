#ifndef STACKTRANSACTIONMETH_H
#define STACKTRANSACTIONMETH_H
#include "StackDailyTransaction.h"
using namespace std;
Stack* CreateStack();
void DestroyStack(Stack* S);
void DisplayStack(const Stack& S);
bool IsStackEmpty(const Stack& S);
bool IsStackFull(const Stack& S);
int StackSize(const Stack& S);
int Push(Stack* S, Transaction t);
Transaction Pop(Stack* S);
Transaction Top(const Stack& S);
Stack* CopyStack(const Stack& S);
bool CompareStacks(const Stack& S1, const Stack& S2);
#endif