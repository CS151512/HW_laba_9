#include "../include/deque_module.h"

DequeRepo::DequeRepo() : head(nullptr), tail(nullptr) {}

DequeRepo::~DequeRepo() {
    int dummy;
    while (pop_front(dummy)) {}
}

void DequeRepo::push_front(int value) {
    DequeNode* newNode = new DequeNode{value, head, nullptr};
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
    if (!tail) {
        tail = head;
    }
}

void DequeRepo::push_back(int value) {
    DequeNode* newNode = new DequeNode{value, nullptr, tail};
    if (tail) {
        tail->next = newNode;
    }
    tail = newNode;
    if (!head) {
        head = tail;
    }
}

bool DequeRepo::pop_front(int& out_value) {
    if (!head) return false;

    DequeNode* temp = head;
    out_value = temp->inf;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    return true;
}

bool DequeRepo::pop_back(int& out_value) {
    if (!tail) return false;

    DequeNode* temp = tail;
    out_value = temp->inf;
    tail = tail->prev;

    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    return true;
}

bool DequeRepo::isEmpty() const {
    return head == nullptr;
}