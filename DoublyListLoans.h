#ifndef DOUBLYLISTLOANS_H
#define DOUBLYLISTLOANS_H
#include <iostream>
#include "Loan.h"
using namespace std;
struct Node_DL {
	Loan data_DL;
	Node_DL* next_DL;
	Node_DL* prev_DL;
};
struct List_DL {
	Node_DL* head_DL;
	Node_DL* tail_DL;
	int size_DL;
};
#endif