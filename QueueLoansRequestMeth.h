#ifndef QUEUELOANSREQUESTMETH_H
#define QUEUELOANSREQUESTMETH_H
#include "QueueLoansRequest.h"

Node_Q* CreateNode_Q(Loan value);
void DestroyNode_Q(Node_Q* node);
Queue* CreateQueue_Q();
void DestroyQueue_Q(Queue* Q);
bool IsFull_Q(const Queue& Q);
bool IsEmpty_Q(const Queue& Q);
int QueueSize_Q(const Queue& Q);
void DisplayQueue_Q(const Queue& Q);
int Enqueue_Q(Queue* Q, Loan e);
Loan Dequeue_Q(Queue* Q);
Loan FrontElement_Q(const Queue& Q);
Queue* CopyQueue_Q(const Queue& Q);
bool CompareQueues_Q(const Queue& Q1, const Queue& Q2);

#endif 