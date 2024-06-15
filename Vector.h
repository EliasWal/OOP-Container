#pragma once
//Luca Stefan

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    size_t sz;
    size_t capacity;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = std::move(data[i]);
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    Vector() : data(nullptr), sz(0), capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    Vector(const Vector& other) : sz(other.sz), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector(Vector&& other) noexcept : data(other.data), sz(other.sz), capacity(other.capacity) {
        other.data = nullptr;
        other.sz = 0;
        other.capacity = 0;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;

        delete[] data;

        sz = other.sz;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        sz = other.sz;
        capacity = other.capacity;

        other.data = nullptr;
        other.sz = 0;
        other.capacity = 0;
        return *this;
    }

    size_t size() const {
        return sz;
    }

    size_t getCapacity() const {
        return capacity;
    }

    bool empty() const {
        return sz == 0;
    }

    T& operator[](size_t index) {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& at(size_t index) {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& at(size_t index) const {
        if (index >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[0];
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[sz - 1];
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return data[sz - 1];
    }

    void push_back(const T& value) {
        if (sz == capacity) {
            reallocate(capacity == 0 ? 1 : 2 * capacity);
        }
        data[sz++] = value;
    }

    void pop_back() {
        if (sz > 0) {
            --sz;
        }
    }

    void clear() {
        sz = 0;
    }

    void insert(size_t pos, const T& value) {
        if (pos > sz) {
            throw std::out_of_range("Index out of range");
        }
        if (sz == capacity) {
            reallocate(capacity == 0 ? 1 : 2 * capacity);
        }
        for (size_t i = sz; i > pos; --i) {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        ++sz;
    }

    void erase(size_t pos) {
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = pos; i < sz - 1; ++i) {
            data[i] = data[i + 1];
        }
        --sz;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            reallocate(new_capacity);
        }
    }

    void resize(size_t new_size) {
        if (new_size > capacity) {
            reallocate(new_size);
        }
        if (new_size > sz) {
            for (size_t i = sz; i < new_size; ++i) {
                data[i] = T();
            }
        }
        sz = new_size;
    }
};
