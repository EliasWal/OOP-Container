#pragma once
//Cristina Iftime

#include "ListIterator.h"
#include <cstddef>

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addToTheEnd(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void addToTheFront(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void removeFromTheEnd() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
            size--;
        }
    }

    void removeFromTheFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
            size--;
        }
    }

    size_t GetSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    Iterator<T> getHeadIterator() const;

    friend class Iterator<T>;  

    bool operator==(const List& other) const {
        if (size != other.size) {
            return false;
        }
        Node* current1 = head;
        Node* current2 = other.head;
        while (current1 && current2) {
            if (current1->data != current2->data) {
                return false;
            }
            current1 = current1->next;
            current2 = current2->next;
        }
        return current1 == nullptr && current2 == nullptr;
    }
};

template <typename T>
Iterator<T> List<T>::getHeadIterator() const {
    return Iterator<T>(head);
}

