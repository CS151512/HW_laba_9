#pragma once

struct Node {
    int inf;
    Node* next;
};

struct DequeNode {
    int inf;
    DequeNode* next;
    DequeNode* prev;
};