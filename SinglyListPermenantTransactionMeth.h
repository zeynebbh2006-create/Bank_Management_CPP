#ifndef SINGLYLINKEDLISTMETH_H
#define SINGLYLINKEDLISTMETH_H
#include "SinglyListPermenantTransaction.h"

Node_SLT* createNode_SLT(Transaction value);
void destroyNode_SLT(Node_SLT* node);
List_SLT createList_SLT();
void destroyList_SLT(List_SLT* L);
bool isEmpty_SLT(const List_SLT& L);
bool isFull_SLT(const List_SLT& L);
int ListSize_SLT(const List_SLT& L);
int insert_SLT(List_SLT* L, Transaction e, int pos);
int removeAt_SLT(List_SLT* L, int pos);
Transaction getElement_SLT(const List_SLT& L, int pos);
void displayList_SLT(const List_SLT& L);
List_SLT CopyList_SLT(const List_SLT& L);
bool CompareLists_SLT(const List_SLT& L1, const List_SLT& L2);

#endif
