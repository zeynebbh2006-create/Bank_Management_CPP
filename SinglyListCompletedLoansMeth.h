#ifndef SINGLYLISTCOMPLETEDLOANSMETH_H
#define SINGLYLISTCOMPLETEDLOANSMETH_H
#include "SinglyListCompletedLoans.h"
Node_SLL* createNode_SLL(Loan value);
void destroyNode_SLL(Node_SLL* node);
List_SLL createList_SLL();
void destroyList_SLL(List_SLL* L);
bool isEmpty_SLL(const List_SLL& L);
bool isFull_SLL(const List_SLL& L);
int ListSize_SLL(const List_SLL& L);
int insert_SLL(List_SLL* L, Loan e, int pos);
int removeAt_SLL(List_SLL* L, int pos);
Loan getElement_SLL(const List_SLL& L, int pos);
void displayList_SLL(const List_SLL& L);
List_SLL CopyList_SLL(const List_SLL& L);
bool CompareLists_SLL(const List_SLL& L1, const List_SLL& L2);

#endif