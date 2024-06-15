#pragma once
//Cristina Iftime
#include "gtest/gtest.h"

template <typename T>
class List;

template <typename T>
class Iterator {
private:
    typename List<T>::Node* current; 

public:
    Iterator(typename List<T>::Node* node) : current(node) {}

    Iterator& operator++() {
        if (current) current = current->next;
        return *this;
    }

    Iterator& operator--() {
        if (current) current = current->prev;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }

    bool operator==(const Iterator& other) const {
        return current == other.current;
    }

    T& operator*() {
        return current->data;
    }
};
#include "gtest/gtest.h"