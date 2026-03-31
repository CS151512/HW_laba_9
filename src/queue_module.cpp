#include "../include/queue_module.h"

QueueRepository::QueueRepository() : head(nullptr), tail(nullptr) {}

QueueRepository::~QueueRepository() {
    int dummy;
    while (pop(dummy)) {}
}

void QueueRepository::push(int value) {
    Node* newNode = new Node{value, nullptr};
    if (tail) {
        tail->next = newNode;
    }
    tail = newNode;

    if (!head) {
        head = tail;
    }
}

bool QueueRepository::pop(int& out_value) {
    if (!head) return false;

    Node* temp = head;
    out_value = temp->inf;
    head = head->next;

    if (!head) {
        tail = nullptr;
    }

    delete temp;
    return true;
}

bool QueueRepository::isEmpty() const {
    return head == nullptr;
}