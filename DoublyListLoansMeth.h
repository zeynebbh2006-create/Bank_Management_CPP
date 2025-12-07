#ifndef DOUBLYLINKEDLISTMETH_H
#define DOUBLYLINKEDLISTMETH_H
#include "DoublyListLoans.h"
Node_DL* createNode_DL(Loan l);
void destroyNode_DL(Node_DL* Node_DL);
List_DL createList_DL();
void destroyList_DL(List_DL* L);
bool isEmpty_DL(const List_DL& L);
bool isFull_DL(const List_DL& L);
int ListSize_DL(const List_DL& L);
int insert_DL(List_DL* L, Loan e, int pos);
int removeAt_DL(List_DL* L, int pos);
Loan getElement_DL(const List_DL& L, int pos);
void displayList_DL(const List_DL& L);
List_DL CopyList_DL(const List_DL& L);
#endif