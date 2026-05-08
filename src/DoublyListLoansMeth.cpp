#include "DoublyListLoansMeth.h"
#include <iostream>
using namespace std;
Node_DL* createNode_DL(Loan value) {
	Node_DL* node = new (nothrow) Node_DL{ value, nullptr, nullptr };
	if (!node) {
		cerr << "\nMemory allocation failed for node\n";
	}
	return node;
}
void destroyNode_DL(Node_DL* node) {
	delete node;
}
List_DL createList_DL() {
	return List_DL{ nullptr, nullptr, 0 };
}
void destroyList_DL(List_DL* L) {
	if (!L) return;
	Node_DL* current = L->head_DL;
	while (current) {
		Node_DL* temp = current;
		current = current->next_DL;
		destroyNode_DL(temp);
	}
	L->head_DL = nullptr;
	L->tail_DL = nullptr;
	L->size_DL = 0;
}
bool isEmpty_DL(const List_DL& L) {
	return L.size_DL == 0;
}
bool isFull_DL(const List_DL& L) {
	Node_DL* test = new (nothrow) Node_DL;
	if (!test) return true;
	delete test;
	return false;
}
int ListSize_DL(const List_DL& L) {
	return L.size_DL;
}
int insert_DL(List_DL* L, Loan e, int pos) {
	if (!L) return 0;
	if (pos < 1 || pos > L->size_DL + 1) {
		cerr << "\nInvalid position";
		return 0;
	}
	Node_DL* n = createNode_DL(e);
	if (!n) return 0;
	if (pos == 1) {
		n->next_DL = L->head_DL;
		if (L->head_DL) {
			L->head_DL->prev_DL = n;
		}
		L->head_DL = n;
		if (L->size_DL == 0) {
			L->tail_DL = n;
		}
	}
	else if (pos == L->size_DL + 1) {
		n->prev_DL = L->tail_DL;
		L->tail_DL->next_DL = n;
		L->tail_DL = n;
	}
	else {
		Node_DL* prev = nullptr;
		Node_DL* current = L->head_DL;
		for (int i = 1; i < pos; i++) {
			prev = current;
			current = current->next_DL;
		}
		prev->next_DL = n;
		n->prev_DL = prev;
		n->next_DL = current;
		current->prev_DL = n;
	}


	L->size_DL++;
	return 1;
}
int removeAt_DL(List_DL* L, int pos) {
	if (!L || isEmpty_DL(*L)) {
		cerr << "\nList is empty";
		return 0;
	}
	if (pos < 1 || pos > L->size_DL) {
		cerr << "\nInvalid position\n";
		return 0;
	}
	Node_DL* current = L->head_DL;
	if (pos == 1) {
		L->head_DL = current->next_DL;
		if (L->head_DL) {
			L->head_DL->prev_DL = nullptr;
		}
		if (L->size_DL == 1) {
			L->tail_DL = nullptr;
		}
	}
	else if (pos == L->size_DL) {
		current = L->tail_DL;
		L->tail_DL = current->prev_DL;
		if (L->tail_DL) {
			L->tail_DL->next_DL = nullptr;
		}
	}
	else {
		for (int i = 1; i < pos; i++) {
			current = current->next_DL;
		}
		current->prev_DL->next_DL = current->next_DL;
		current->next_DL->prev_DL = current->prev_DL;
	}
	destroyNode_DL(current);
	L->size_DL--;
	return 1;
}
Loan getElement_DL(const List_DL& L, int pos) {
	if (isEmpty_DL(L)) {
		cerr << "\nList is empty\n";
		return Loan{};
	}
	if (pos < 1 || pos > L.size_DL) {
		cerr << "\nInvalid position\n";
		return Loan{};
	}
	const Node_DL* current = L.head_DL;
	for (int i = 1; i < pos; i++) {
		if (!current) {
			cerr << "\nList structure error\n";
			return Loan{};
		}
		current = current->next_DL;
	}
	return current->data_DL;
}
void displayList_DL(const List_DL& L) {
	if (isEmpty_DL(L)) {
		cout << "List is empty\n";
		return;
	}
	Node_DL* current = L.head_DL;
	while (current) {
		cout << current->data_DL.loanID << " -> ";
		current = current->next_DL;
	}
	cout << "NULL\n";
}
List_DL CopyList_DL(const List_DL& L) {
	List_DL newList = createList_DL();
	Node_DL* current = L.head_DL;
	Node_DL* tail = nullptr;
	while (current) {
		Node_DL* newNode = createNode_DL(current->data_DL);
		if (!newNode) {
			destroyList_DL(&newList);
			return newList;
		}
		if (!newList.head_DL) {
			newList.head_DL = newNode;
			tail = newNode;
		}
		else {
			tail->next_DL = newNode;
			newNode->prev_DL = tail;
			tail = newNode;
		}
		current = current->next_DL;
	}
	newList.tail_DL = tail;
	newList.size_DL = L.size_DL;
	return newList;
}


