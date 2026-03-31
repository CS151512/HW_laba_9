#include "../include/stack_module.h"

StackRepo::StackRepo() : head(nullptr) {}

StackRepo::~StackRepo() {
    int dummy;
    while (pop(dummy)) {}
}

void StackRepo::push(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

bool StackRepo::pop(int& out_value) {
    if (!head) return false;
    Node* temp = head;
    out_value = temp->inf;
    head = head->next;
    delete temp;
    return true;
}

bool StackRepo::isEmpty() const {
    return head == nullptr;
}

void StackRepo::replaceHead(Node* newHead) {
    head = newHead;
}

Node* StackRepo::getHead() const {
    return head;
}

void StackService::reverse(StackRepo& stack) {
    StackRepo tempStack;
    int value;

    while (stack.pop(value)) {
        tempStack.push(value);
    }

    stack.replaceHead(tempStack.getHead());

    tempStack.replaceHead(nullptr);
}

std::vector<int> StackService::getElementsViaDubleReverse(StackRepo& stack) {
    std::vector<int> elements;
    if (stack.isEmpty()) return elements;

    reverse(stack);

    StackRepo originalStack;
    int value;

    while (stack.pop(value)) {
        elements.push_back(value);
        originalStack.push(value);
    }

    stack.replaceHead(originalStack.getHead());
    originalStack.replaceHead(nullptr);

    return elements;
}