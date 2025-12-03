#pragma once
#include "OpAmp.h"

struct Node {
    OpAmp data;
    Node* next;

    Node(const OpAmp& val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void push_front(const OpAmp& val);
    void push_back(const OpAmp& val);
    void insert_after(const OpAmp& target, const OpAmp& val);

    void pop_front();
    void pop_back();
    void remove_val(const OpAmp& val);

    void display() const;
    bool is_empty() const;
    void clear();
};
