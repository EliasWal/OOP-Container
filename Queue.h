#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int size;
    int first;
    int last;

public:
    Queue(int initial_capacity = 5) {
        this->capacity = initial_capacity;
        this->size = 0;
        this->first = 0;
        this->last = -1;
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void push(const T& value) {
        if (size == capacity) {
            //dublam capacitatea
            T* new_data = new T[capacity * 2];

            for (int i = 0; i < size; i++) {
                new_data[i] = data[(first + i) % capacity];
            }

            delete[] data;
            data = new_data;
            capacity = capacity * 2;
            first = 0;
            last = size - 1;
        }
        last = (last + 1) % capacity;
        data[last] = value;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Empty queue! ";
        }
        first = (first + 1) % capacity;
        size--;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if (size == 0) return true;
        return false;
    }

    T& getFirstElement() {
        if (size == 0) {
            cout << "Empty queue! ";
        }
        return data[first];
    }

    T& getLastElement() {
        if (size == 0) {
            cout << "Empty queue! ";
        }
        return data[last];
    }

    void swap(Queue<T>& other) {
        std::swap(data, other.data);
        std::swap(capacity, other.capacity);
        std::swap(size, other.size);
        std::swap(first, other.first);
        std::swap(last, other.last);
    }

    void print() {
        if (size == 0) {
            cout << "Empty queue!" << endl;
            return;
        }

        cout << "Elements: ";
        int current = first;
        for (int i = 0; i < size; i++) {
            cout << data[current] << " ";
            current = (current + 1) % capacity;
        }
        cout << endl;
    }

    void clear() {
        delete[] data;
        capacity = 5;
        size = 0;
        first = 0;
        last = -1;
        data = new T[capacity];
    }

    T& operator[](int index) {
        if (index >= size || index < 0) {
            cout << "Index out of range! ";
        }
        return data[(first + index) % capacity];
    }

    bool operator==(Queue& other) {
        if (size != other.getSize()) {
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if ((*this)[i] != other[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(Queue& other) {
        return !(*this == other);
    }

    T& begin() {
        return data[first];
    }

    T& end() {
        return data[last];
    }
};
