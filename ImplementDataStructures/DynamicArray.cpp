//
// Created by Joel Jose Ginga on 15/02/2024.
//

/**
 * Design a Dynamic Array (aka a resizable array) class, such as an ArrayList in Java or a vector in C++.

    Your DynamicArray class should support the following operations:

    DynamicArray(int capacity) will initialize an empty array with a capacity of capacity, where capacity > 0.
        int get(int i) will return the element at index i. Assume that index i is valid.
        void set(int i, int n) will set the element at index i to n. Assume that index i is valid.
        void pushback(int n) will push the element n to the end of the array.
        int popback() will pop and return the element at the end of the array. Assume that the array is non-empty.
        void resize() will double the capacity of the array.
        int getSize() will return the number of elements in the array.
        int getCapacity() will return the capacity of the array.
    If we call void pushback(int n) but the array is full, we should resize the array first.
 */

#include <memory>

class DynamicArray {

private:
    //state
    std::unique_ptr<int[]> data; //smart pointer for dynamic memory allocation
    size_t capacity; //size of the array
    size_t size; //number of elements in the array

public:

    //constructor
    DynamicArray(int capacity)
            : size(0), capacity(capacity), data(new int[capacity]){};


    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();

        data[size] = n;
        size++;
    }

    int popback() {
        return data[--size];
    }

    void resize() {
        capacity *= 2;
        std::unique_ptr<int[]> newData(new int[capacity]);
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = std::move(newData);

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};