#pragma once
#include "models.h"
#include "vector"

class StackRepo {
private:
    Node* head;
public:
    StackRepo();
    ~StackRepo();

    void push(int value);
    bool pop(int& out_value);
    bool isEmpty() const;

    void replaceHead(Node* newHead);
    Node* getHead() const;
};

class StackService {
public:
    static void reverse(StackRepo& stack);
    static std::vector<int> getElementsViaDubleReverse(StackRepo& stack);
};