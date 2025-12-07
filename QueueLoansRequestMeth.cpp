#include "QueueLoansRequestMeth.h"
#include <iostream>
#include "GlobalVariables.h" 
using namespace std;

// Create a new node
Node_Q* CreateNode_Q(Loan value) {
    Node_Q* node = new (nothrow) Node_Q;
    if (!node) {
        cerr << "\nMemory allocation failed for node\n";
        return nullptr;
    }
    node->data_Q = value;
    node->next_Q = nullptr;
    return node;
}

// Destroy a node
void DestroyNode_Q(Node_Q* node) {
    delete node;
}

// Create queue
Queue* CreateQueue_Q() {
    Queue* Q = new(nothrow) Queue;
    if (!Q)
        cout << "\nError: unable to allocate memory\n";
    else {
        Q->front_Q = nullptr;
        Q->tail_Q = nullptr;
    }
    return Q;
}

// Destroy queue
void DestroyQueue_Q(Queue* Q) {
    Node_Q* n = Q->front_Q;
    while (n != nullptr) {
        Q->front_Q = n->next_Q;
        DestroyNode_Q(n);
        n = Q->front_Q;
    }
    delete Q;
}

bool IsEmpty_Q(const Queue& Q) {
    return (Q.front_Q == nullptr);
}

bool IsFull_Q(const Queue& Q) {
    Node_Q* temp = new(nothrow) Node_Q;
    bool full = (temp == nullptr);
    if (temp)
        delete temp;
    return full;
}

int QueueSize_Q(const Queue& Q) {
    int size = 0;
    Node_Q* n = Q.front_Q;
    while (n != nullptr) {
        size++;
        n = n->next_Q;
    }
    return size;
}

void DisplayQueue_Q(const Queue& Q) {
    Node_Q* n = Q.front_Q;
    while (n != nullptr) {
        cout << n->data_Q.loanID << " -> ";
        n = n->next_Q;
    }
    cout << "NULL\n";
}

int Enqueue_Q(Queue* Q, Loan e) {
    if (IsFull_Q(*Q)) {
        cout << "\nQueue is full";
        return 0;
    }

    Node_Q* n = CreateNode_Q(e);

    if (IsEmpty_Q(*Q)) {
        Q->front_Q = n;
        Q->tail_Q = n;
    }
    else {
        Q->tail_Q->next_Q = n;
        Q->tail_Q = n;
    }

    return 1;
}

Loan Dequeue_Q(Queue* Q) {
    Loan e = {};

    if (IsEmpty_Q(*Q)) {
        cout << "\nQueue is empty";
        return e;
    }

    Node_Q* n = Q->front_Q;
    e = n->data_Q;

    Q->front_Q = n->next_Q;
    if (Q->front_Q == nullptr)
        Q->tail_Q = nullptr;

    DestroyNode_Q(n);

    return e;
}

Loan FrontElement_Q(const Queue& Q) {
    Loan e = {};
    if (IsEmpty_Q(Q))
        cout << "\nQueue is empty";
    else
        e = Q.front_Q->data_Q;
    return e;
}

Queue* CopyQueue_Q(const Queue& Q) {
    Queue* newQ = CreateQueue_Q();
    Node_Q* curr = Q.front_Q;
    Node_Q* last = nullptr;

    while (curr != nullptr) {
        Node_Q* newNode = CreateNode_Q(curr->data_Q);

        if (newQ->front_Q == nullptr) {
            newQ->front_Q = newNode;
            last = newNode;
        }
        else {
            last->next_Q = newNode;
            last = newNode;
        }

        curr = curr->next_Q;
    }

    newQ->tail_Q = last;
    return newQ;
}

bool CompareQueues_Q(const Queue& Q1, const Queue& Q2) {
    Node_Q* n1 = Q1.front_Q;
    Node_Q* n2 = Q2.front_Q;

    while (n1 != nullptr && n2 != nullptr) {
        if (n1->data_Q.loanID != n2->data_Q.loanID)
            return false;

        n1 = n1->next_Q;
        n2 = n2->next_Q;
    }

    return (n1 == nullptr && n2 == nullptr);
}
