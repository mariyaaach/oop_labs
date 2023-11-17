#pragma once
#include <iostream>
#include <map>
#include <vector>

template <class T, size_t N>
class MyAllocator {
public:
    using value_type = T;

    template <class U>
    struct rebind {
        using other = MyAllocator<U, N>;
    };

    MyAllocator() noexcept {}

    template <class U>
    MyAllocator(const MyAllocator<U, N>&) noexcept {}

    T* allocate(size_t n) {
        if (n > N) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, size_t n) noexcept {
        ::operator delete(p);
    }
};