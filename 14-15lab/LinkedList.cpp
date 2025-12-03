#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

bool LinkedList::is_empty() const {
    return head == nullptr;
}

void LinkedList::push_front(const OpAmp& val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void LinkedList::push_back(const OpAmp& val) {
    Node* newNode = new Node(val);
    if (is_empty()) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::insert_after(const OpAmp& target, const OpAmp& val) {
    if (is_empty()) throw OpAmpException("Список порожній.");

    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    throw OpAmpException("Елемент для вставки після нього не знайдено.");
}

void LinkedList::pop_front() {
    if (is_empty()) throw OpAmpException("Список порожній, видалення неможливе.");

    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::pop_back() {
    if (is_empty()) throw OpAmpException("Список порожній, видалення неможливе.");

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void LinkedList::remove_val(const OpAmp& val) {
    if (is_empty()) throw OpAmpException("Список порожній.");

    if (head->data == val) {
        pop_front();
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == val) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        current = current->next;
    }
    throw OpAmpException("Елемент для видалення не знайдено.");
}

void LinkedList::display() const {
    if (is_empty()) {
        std::cout << "Список порожній." << std::endl;
        return;
    }
    Node* current = head;
    int i = 1;
    while (current != nullptr) {
        std::cout << i++ << ". " << current->data << std::endl;
        current = current->next;
    }
}