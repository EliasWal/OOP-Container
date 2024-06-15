#pragma once
//Azoitei Paul

#include <iostream>
#include <stdexcept>

template <class T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& _data) : data(_data), next(nullptr) {}
    };

    Node* head;
    int Size;

public:
    ForwardList() : head(nullptr), Size(0) {}

    ~ForwardList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++Size;
    }

    void pop_front() {
        if (head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        --Size;
    }

    T& front() {
        if (head == nullptr) {
            throw std::out_of_range("ForwardList is empty");
        }
        return head->data;
    }

    int size() const {
        return Size;
    }

    bool empty() const {
        return Size == 0;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};