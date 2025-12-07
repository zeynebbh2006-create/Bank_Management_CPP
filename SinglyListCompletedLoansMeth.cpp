#include "SinglyListCompletedLoans.h"
#include <iostream>
using namespace std;

// Create a new node
Node_SLL* createNode_SLL(Loan value) {
    Node_SLL* node = new(nothrow) Node_SLL{ value, nullptr };
    if (!node) {
        cerr << "\nMemory allocation failed for node\n";
    }
    return node;
}

// Destroy a node
void destroyNode_SLL(Node_SLL* node) {
    delete node;
}

// Create list
List_SLL createList_SLL() {
    return List_SLL{ nullptr, 0 };
}

// Destroy list
void destroyList_SLL(List_SLL* L) {
    if (!L) return;

    Node_SLL* cur = L->head_SLL;
    while (cur) {
        Node_SLL* temp = cur;
        cur = cur->next_SLL;
        destroyNode_SLL(temp);
    }
    L->head_SLL = nullptr;
    L->size_SLL = 0;
}

// Check if empty
bool isEmpty_SLL(const List_SLL& L) {
    return L.size_SLL == 0;
}

// Check if full
bool isFull_SLL(const List_SLL& L) {
    Node_SLL* test = new(nothrow) Node_SLL;
    if (!test) return true;
    delete test;
    return false;
}

// Return size
int ListSize_SLL(const List_SLL& L) {
    return L.size_SLL;
}

// Insertion at position
int insert_SLL(List_SLL* L, Loan e, int pos) {
    if (!L) return 0;
    if (pos < 1 || pos > L->size_SLL + 1) {
        cerr << "\nInvalid position";
        return 0;
    }

    Node_SLL* n = createNode_SLL(e);
    if (!n) return 0;

    if (pos == 1) {
        n->next_SLL = L->head_SLL;
        L->head_SLL = n;
    }
    else {
        Node_SLL* prev = nullptr;
        Node_SLL* cur = L->head_SLL;

        for (int i = 1; i < pos; i++) {
            prev = cur;
            cur = cur->next_SLL;
        }

        prev->next_SLL = n;
        n->next_SLL = cur;
    }

    L->size_SLL++;
    return 1;
}

// Remove at position
int removeAt_SLL(List_SLL* L, int pos) {
    if (!L || isEmpty_SLL(*L)) {
        cerr << "\nList is empty";
        return 0;
    }

    if (pos < 1 || pos > L->size_SLL) {
        cerr << "\nInvalid position";
        return 0;
    }

    Node_SLL* cur = L->head_SLL;
    Node_SLL* prev = nullptr;

    if (pos == 1) {
        L->head_SLL = cur->next_SLL;
    }
    else {
        for (int i = 1; i < pos; i++) {
            prev = cur;
            cur = cur->next_SLL;
        }
        prev->next_SLL = cur->next_SLL;
    }

    destroyNode_SLL(cur);
    L->size_SLL--;
    return 1;
}

// Get element
Loan getElement_SLL(const List_SLL& L, int pos) {
    if (isEmpty_SLL(L)) {
        cerr << "\nList is empty\n";
        return {};
    }

    if (pos < 1 || pos > L.size_SLL) {
        cerr << "\nInvalid position\n";
        return {};
    }

    Node_SLL* cur = L.head_SLL;
    for (int i = 1; i < pos; i++) {
        cur = cur->next_SLL;
    }

    return cur->data_SLL;
}

// Display list
void displayList_SLL(const List_SLL& L) {
    if (isEmpty_SLL(L)) {
        cout << "List is empty\n";
        return;
    }

    Node_SLL* cur = L.head_SLL;
    while (cur) {
        cout << cur->data_SLL.loanID << " -> ";
        cur = cur->next_SLL;
    }
    cout << "NULL\n";
}

// Copy list
List_SLL CopyList_SLL(const List_SLL& L) {
    List_SLL newList = createList_SLL();

    Node_SLL* cur = L.head_SLL;
    Node_SLL* tail = nullptr;

    while (cur) {
        Node_SLL* n = createNode_SLL(cur->data_SLL);
        if (!n) {
            destroyList_SLL(&newList);
            return createList_SLL();
        }

        if (!newList.head_SLL) {
            newList.head_SLL = n;
            tail = n;
        }
        else {
            tail->next_SLL = n;
            tail = n;
        }

        cur = cur->next_SLL;
    }

    newList.size_SLL = L.size_SLL;
    return newList;
}

// Compare lists
bool CompareLists_SLL(const List_SLL& L1, const List_SLL& L2) {
    if (L1.size_SLL != L2.size_SLL) return false;

    Node_SLL* p1 = L1.head_SLL;
    Node_SLL* p2 = L2.head_SLL;

    while (p1) {
        if (p1->data_SLL.loanID != p2->data_SLL.loanID)
            return false;

        p1 = p1->next_SLL;
        p2 = p2->next_SLL;
    }

    return true;
}
