#pragma once
//Popa Maria-Eliza

#include <cstring>  

template <typename K, typename V>
struct Object {
    K key;
    V value;
    int index;
};

template <typename K, typename V>
class Map {
    Object<K, V>* array;
    int maxsize;
    int position;

    void resize() {
        Object<K, V>* arr = new Object<K, V>[maxsize * 2] {};
        std::memcpy(arr, array, sizeof(Object<K, V>) * maxsize);
        delete[] array;
        array = arr;
        maxsize *= 2;
    }

public:
    Map() : maxsize(1), position(0) {
        array = new Object<K, V>[maxsize];
    }

    ~Map() {
        delete[] array;
    }

    V& operator[](K key) {
        for (int i = 0; i < position; ++i) {
            if (array[i].key == key)
                return array[i].value;
        }

        if (position == maxsize)
            resize();

        array[position].key = key;
        array[position].index = position;
        return array[position++].value;
    }

    void Set(K key, V value) {
        for (int i = 0; i < position; ++i) {
            if (array[i].key == key) {
                array[i].value = value;
                return;
            }
        }

        if (position == maxsize)
            resize();

        array[position].key = key;
        array[position].value = value;
        array[position].index = position;
        ++position;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < position; ++i) {
            if (array[i].key == key) {
                value = array[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return position;
    }

    void Clear() {
        delete[] array;
        maxsize = 1;
        position = 0;
        array = new Object<K, V>[maxsize];
    }

    bool Delete(const K& key) {
        for (int i = 0; i < position; ++i) {
            if (array[i].key == key) {
                for (int j = i; j < position - 1; ++j)
                    array[j] = array[j + 1];
                --position;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        if (map.position > position)
            return false;

        V value;
        for (int i = 0; i < map.position; ++i) {
            if (!Get(map.array[i].key, value)) {
                return false;
            }
            if constexpr (std::is_same_v<V, const char*>) {
                if (strcmp(value, map.array[i].value) != 0) {
                    return false;
                }
            }
            else {
                if (value != map.array[i].value) {
                    return false;
                }
            }
        }
        return true;
    }


    Object<K, V>* begin() const {
        return array;
    }

    Object<K, V>* end() const {
        return array + position;
    }
};
