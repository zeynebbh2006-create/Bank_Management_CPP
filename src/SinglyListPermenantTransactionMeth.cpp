#include "SinglyListPermenantTransactionMeth.h"
#include <iostream>
using namespace std;

//Create a new node
Node_SLT* createNode_SLT(Transaction value) {
    Node_SLT* node = new (nothrow) Node_SLT{ value, nullptr };
    if (!node) {
        cerr << "\nMemory allocation failed for node\n";
    }
    return node;
}

//Destroy a node
void destroyNode_SLT(Node_SLT* node) {
    delete node;
}

//Check if empty
bool isEmpty_SLT(const List_SLT& L) {
    return L.size_SLT == 0;
}

//Check if full
bool isFull_SLT(const List_SLT& L) {
    Node_SLT* test = new (nothrow) Node_SLT;
    if (!test) return true;
    delete test;
    return false;
}

//Return size
int ListSize_SLT(const List_SLT& L) {
    return L.size_SLT;
}

//Insertion
int insert_SLT(List_SLT* L, Transaction e, int pos) {
    if (!L) return 0;
    if (pos < 1 || pos > L->size_SLT + 1) {
        cerr << "\nInvalid position";
        return 0;
    }

    Node_SLT* n = createNode_SLT(e);
    if (!n) return 0;

    if (pos == 1) {
        n->next_SLT = L->head_SLT;
        L->head_SLT = n;
    }
    else {
        Node_SLT* prev = nullptr;
        Node_SLT* current = L->head_SLT;
        for (int i = 1; i < pos; i++) {
            prev = current;
            current = current->next_SLT;
        }
        prev->next_SLT = n;
        n->next_SLT = current;
    }

    L->size_SLT++;
    return 1;
}

//Deletion
int removeAt_SLT(List_SLT* L, int pos) {
    if (!L || isEmpty_SLT(*L)) {
        cerr << "\nList is empty";
        return 0;
    }
    if (pos < 1 || pos > L->size_SLT) {
        cerr << "\nInvalid position";
        return 0;
    }

    Node_SLT* prev = nullptr;
    Node_SLT* current = L->head_SLT;

    if (pos == 1) {
        L->head_SLT = current->next_SLT;
    }
    else {
        for (int i = 1; i < pos; i++) {
            prev = current;
            current = current->next_SLT;
        }
        prev->next_SLT = current->next_SLT;
    }

    destroyNode_SLT(current);
    L->size_SLT--;
    return 1;
}

//Get element
Transaction getElement_SLT(const List_SLT& L, int pos) {
    if (isEmpty_SLT(L)) {
        cerr << "\nList is empty\n";
        return {};
    }

    if (pos < 1 || pos > L.size_SLT) {
        cerr << "\nInvalid position\n";
        return {};
    }

    Node_SLT* current = L.head_SLT;
    for (int i = 1; i < pos; i++) {
        current = current->next_SLT;
    }

    return current->data_SLT;
}

//Create list
List_SLT createList_SLT() {
    return List_SLT{ nullptr, 0 };
}

//Destroy list
void destroyList_SLT(List_SLT* L) {
    if (!L) return;

    Node_SLT* current = L->head_SLT;
    while (current) {
        Node_SLT* temp = current;
        current = current->next_SLT;
        destroyNode_SLT(temp);
    }

    L->head_SLT = nullptr;
    L->size_SLT = 0;
}

//Display list
void displayList_SLT(const List_SLT& L) {
    if (isEmpty_SLT(L)) {
        cout << "List is empty\n";
        return;
    }

    Node_SLT* current = L.head_SLT;
    while (current) {
        cout << current->data_SLT.transactionID << " -> ";
        current = current->next_SLT;
    }
    cout << "NULL\n";
}

//Copy list
List_SLT CopyList_SLT(const List_SLT& L) {
    List_SLT newList = createList_SLT();
    Node_SLT* current = L.head_SLT;
    Node_SLT* tail = nullptr;

    while (current) {
        Node_SLT* n = createNode_SLT(current->data_SLT);

        if (!n) {
            cerr << "\nMemory allocation failed while copying\n";
            destroyList_SLT(&newList);
            return createList_SLT();
        }

        if (!newList.head_SLT) {
            newList.head_SLT = n;
            tail = n;
        }
        else {
            tail->next_SLT = n;
            tail = n;
        }

        current = current->next_SLT;
    }

    newList.size_SLT = L.size_SLT;
    return newList;
}

//Compare lists
bool CompareLists_SLT(const List_SLT& L1, const List_SLT& L2) {
    if (L1.size_SLT != L2.size_SLT) return false;

    Node_SLT* p1 = L1.head_SLT;
    Node_SLT* p2 = L2.head_SLT;

    while (p1) {
        if (p1->data_SLT.transactionID != p2->data_SLT.transactionID)
            return false;

        p1 = p1->next_SLT;
        p2 = p2->next_SLT;
    }
    return true;
}
