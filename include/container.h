#pragma once
#include "allocator.h"

template <class T, size_t N, class Alloc = MyAllocator<T, N>>
class MyContainer {
public:
    using value_type = T;
    using allocator_type = Alloc;

    MyContainer() : data(allocator_type().allocate(N)), size(0), capacity(N) {}

    void push_back(const T& value) {
        if (size == capacity) {
            // reallocate
            T* new_data = allocator_type().allocate(capacity * 2);
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            allocator_type().deallocate(data, capacity);
            data = new_data;
            capacity *= 2;
        }
        data[size++] = value;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

public:
    T* data;
    size_t size;
    size_t capacity;
};
