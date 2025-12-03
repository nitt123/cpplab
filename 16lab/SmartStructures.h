#pragma once
#include <memory>
#include <iostream>
#include "OpAmp.h"

class ChildB;

class ChildA {
public:
    std::shared_ptr<ChildB> ptrB;

    ChildA() { std::cout << "  [A] Створено" << std::endl; }
    ~ChildA() { std::cout << "  [A] Знищено" << std::endl; }
};

class ChildB {
public:
    std::weak_ptr<ChildA> ptrA;

    ChildB() { std::cout << "  [B] Створено" << std::endl; }
    ~ChildB() { std::cout << "  [B] Знищено" << std::endl; }
};

class ListNode {
public:
    OpAmp data;
    std::shared_ptr<ListNode> next;
    std::weak_ptr<ListNode> prev;

    ListNode(const OpAmp& val) : data(val) {}
    ~ListNode() {
        std::cout << "  [List Node] Вузол з " << data.getGain() << " видалено." << std::endl;
    }
};