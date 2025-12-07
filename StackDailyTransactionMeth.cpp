#include "StackDailyTransactionMeth.h"
#include <iostream>
using namespace std;
Stack* CreateStack() {
	Stack* S = new (nothrow) Stack;
	if (!S) {
		cout << "\n Error: unable to allocate memory";
	}
	else {
		S->Top = 0;
	}
	return S;
}
void DestroyStack(Stack* S) {
	delete S;
}
void DisplayStack(const Stack& S) {
	if (IsStackEmpty(S)) {
		cout << "\nStack is empty\n";
		return;
	}
	cout << "\nStack elements:\n";
	for (int i = S.Top; i >= 1; i--) {
		cout << "Transaction ID: " << S.element[i].transactionID << ", Account Number: " << S.element[i].accountNumber
			<< ", Type: " << S.element[i].type << ", Amount: " << S.element[i].amount
			<< ", Date: " << S.element[i].date << endl;
	}
}
bool IsStackEmpty(const Stack& S) {
	return S.Top == 0;
}
bool IsStackFull(const Stack& S) {
	return S.Top == Max;
}
int StackSize(const Stack& S) {
	return S.Top;
}
int Push(Stack* S, Transaction t) {
	if (!S) return 0;
	if (IsStackFull(*S)) {
		cerr << "\nStack is full\n";
		return 0;
	}
	S->element[S->Top] = t;
	S->Top++;
	return 1;
}
Transaction Pop(Stack* S) {
	Transaction e{};
	if (IsStackEmpty(*S)) {
		cout << "\nStack is empty";
		return e;
	}
	S->Top--;
	e = S->element[S->Top];
	return e;
}
Transaction Top(const Stack& S) {
	Transaction t{};
	if (IsStackEmpty(S)) {
		cerr << "Stack is empty\n";
		return t;
	}
	return S.element[S.Top - 1];
}
Stack* CopyStack(const Stack& S) {
	Stack* newStack = CreateStack();
	if (!newStack) return nullptr;
	for (int i = 0; i < S.Top; i++) {
		newStack->element[i] = S.element[i];
	}
	newStack->Top = S.Top;
	return newStack;
}
bool CompareStacks(const Stack& S1, const Stack& S2) {
	if (StackSize(S1) != StackSize(S2)) {
		return false;
	}
	int i = 1; // start from the first element (1-based indexing)
	bool equal = true;
	while (i <= S1.Top && equal) {
		if (S1.element[i].transactionID != S2.element[i].transactionID || S1.element[i].accountNumber != S2.element[i].accountNumber || S1.element[i].type != S2.element[i].type || S1.element[i].amount != S2.element[i].amount || S1.element[i].date != S2.element[i].date) {
			equal = false;
		}
		i++;
	}
	return equal;
}


