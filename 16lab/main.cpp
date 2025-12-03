#include <iostream>
#include <memory>
#include <windows.h>
#include "OpAmp.h"
#include "SmartStructures.h"

void taskUniquePtr() {
    std::cout << "\n=== ЗАВДАННЯ 2: std::unique_ptr ===" << std::endl;

    std::unique_ptr<OpAmp> item1 = std::make_unique<OpAmp>(10.0, 5.0, 2);
    std::cout << "item1 створено. Адреса: " << item1.get() << std::endl;

    std::cout << "Переміщення item1 в item2..." << std::endl;
    std::unique_ptr<OpAmp> item2 = std::move(item1);

    if (item1 == nullptr) {
        std::cout << "item1 тепер порожній (nullptr)." << std::endl;
    }
    std::cout << "item2 володіє об'єктом. Дані: " << *item2 << std::endl;

    std::cout << "Вихід з функції taskUniquePtr. Зараз спрацює деструктор item2..." << std::endl;
}

void taskSharedPtr() {
    std::cout << "\n=== ЗАВДАННЯ 3: std::shared_ptr ===" << std::endl;

    std::shared_ptr<OpAmp> ptr1 = std::make_shared<OpAmp>(50.0, 12.0, 4);
    std::cout << "ptr1 створено. use_count: " << ptr1.use_count() << std::endl;

    {
        std::cout << "--- Вхід у внутрішній блок ---" << std::endl;
        std::shared_ptr<OpAmp> ptr2 = ptr1;
        std::cout << "Створено ptr2 (копія). use_count: " << ptr1.use_count() << std::endl;

        std::shared_ptr<OpAmp> ptr3 = ptr2;
        std::cout << "Створено ptr3 (копія). use_count: " << ptr1.use_count() << std::endl;
        std::cout << "--- Вихід з внутрішнього блоку ---" << std::endl;
    }

    std::cout << "Повернулися в основний блок. use_count: " << ptr1.use_count() << std::endl;
    std::cout << "Завершення taskSharedPtr. Знищення об'єкта..." << std::endl;
}

void taskWeakPtrCycle() {
    std::cout << "\n=== ЗАВДАННЯ 4: Cyclic Reference (weak_ptr) ===" << std::endl;

    std::shared_ptr<ChildA> a = std::make_shared<ChildA>();
    std::shared_ptr<ChildB> b = std::make_shared<ChildB>();

    std::cout << "Встановлення зв'язків A -> B та B -> A (weak)..." << std::endl;
    a->ptrB = b;
    b->ptrA = a;

    std::cout << "Лічильник посилань A: " << a.use_count() << std::endl;
    std::cout << "Лічильник посилань B: " << b.use_count() << std::endl;
    std::cout << "Вихід з функції. Деструктори мають спрацювати." << std::endl;
}

void taskLinkedList() {
    std::cout << "\n=== ЗАВДАННЯ 5: Список на Smart Pointers ===" << std::endl;

    auto node1 = std::make_shared<ListNode>(OpAmp(100.0, 15.0, 2));
    auto node2 = std::make_shared<ListNode>(OpAmp(200.0, 15.0, 2));
    auto node3 = std::make_shared<ListNode>(OpAmp(300.0, 15.0, 2));

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    std::cout << "Список створено: Node1 -> Node2 -> Node3" << std::endl;

    std::cout << "Прямий прохід:" << std::endl;
    std::shared_ptr<ListNode> current = node1;
    while (current) {
        std::cout << " -> " << current->data << std::endl;
        current = current->next;
    }

    std::cout << "Зворотний прохід (від Node3):" << std::endl;
    current = node3;
    while (current) {
        std::cout << " -> " << current->data << std::endl;
        current = current->prev.lock();
    }

    std::cout << "Очищення списку (автоматично)..." << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    taskUniquePtr();
    taskSharedPtr();
    taskWeakPtrCycle();
    taskLinkedList();

    std::cout << "\nПрограма завершена." << std::endl;
    return 0;
}