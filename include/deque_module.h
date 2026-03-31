#pragma once
#include "models.h"

class DequeRepo {
private:
    DequeNode* head;
    DequeNode* tail;
public:
    DequeRepo();
    ~DequeRepo();

    void push_front(int value);
    void push_back(int value);
    bool pop_front(int& out_value);
    bool pop_back(int& out_value);
    bool isEmpty() const;
};

class DequeService {
public: //тут пусто :( но так надо
};