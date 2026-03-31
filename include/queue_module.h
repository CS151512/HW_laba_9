#pragma once
#include "models.h"

class QueueRepository {
private:
    Node* head;
    Node* tail;

public:
    QueueRepository();
    ~QueueRepository();

    void push(int value);
    bool pop(int& out_value);
    bool isEmpty() const;
};

class QueueService {
public:// и тут тоже пусто :(
};