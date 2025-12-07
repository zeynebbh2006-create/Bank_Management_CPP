#ifndef SINGLYLISTCOMPLETEDLOANS_H
#define SINGLYLISTCOMPLETEDLOANS_H
#include "Loan.h"
struct Node_SLL {
	Loan data_SLL;
	Node_SLL* next_SLL = nullptr;
};

struct List_SLL {
	Node_SLL* head_SLL;
	int size_SLL;
};
#endif