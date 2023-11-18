#pragma once
#include <iostream>
#include <map>
#include <vector>

template <class T, size_t N>
class MyAllocator {
public:
    //использование typedef для определения псевдонима value_type для типа t
    using value_type = T;

    //вложенная структура rebind для переопределения аллокатора для другого типа u и размера n
    template <class U>
    struct rebind {
        using other = MyAllocator<U, N>;
    };

    //конструктор по умолчанию
    //noexcept показывает что исключений не будет
    MyAllocator() noexcept {}

    //конструктор копирования
    //noexcept указывает, что конструктор не будет генерировать исключения
    template <class U>
    MyAllocator(const MyAllocator<U, N>&) noexcept {}

    //функция allocate для выделения памяти под n объектов типа T.
    //если n больше, чем N, генерируется исключение std::bad_alloc.
    T* allocate(size_t n) {
        if (n > N) {
            throw std::bad_alloc();
        }
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    //функция deallocate для освобождения выделенной памяти, на которую указывает p
    //аргумент n используется для согласования с требованиями стандартного аллокатора, но не используется
    //noexcept указывает, что функция не будет генерировать исключения
    void deallocate(T* p, size_t n) noexcept {
        ::operator delete(p);
    }
};