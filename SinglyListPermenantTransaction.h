#ifndef SINGLYLISTPERMENANTTRANSACTION_H
#define SINGLYLISTPERMENANTTRANSACTION_H
#include "Transaction.h"
struct Node_SLT {
	Transaction data_SLT;
	Node_SLT* next_SLT;
};

struct List_SLT {
	Node_SLT* head_SLT;
	int size_SLT;
};
#endif