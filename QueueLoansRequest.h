#ifndef QUEUELOANREQUEST_H
#define QUEUELOANREQUEST_H
#include "Loan.h"

struct Node_Q {
	Loan data_Q{};
	Node_Q* next_Q = nullptr;
};
struct Queue {
	Node_Q* front_Q = nullptr;
	Node_Q* tail_Q = nullptr;
};
#endif
