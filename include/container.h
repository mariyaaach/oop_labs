#pragma once
#include "allocator.h"

template <class T, size_t N, class Alloc = MyAllocator<T, N>> //объявление шаблонного класса MyContainer с параметрами T, N и Alloc по умолчанию
class MyContainer {
public:
    using value_type = T; //определение псевдонима value_type для типа T
    using allocator_type = Alloc; //определение псевдонима allocator_type для типа Alloc

    MyContainer() : data(allocator_type().allocate(N)), size(0), capacity(N) {} // конструктор по умолчанию, выделяющий память для массива размера N

    void push_back(const T& value) { //метод для добавления элемента в контейнер
        if (size == capacity) { //если размер равен вместимости, то
            T* new_data = allocator_type().allocate(capacity * 2); //выделяется новая память в два раза больше
            for (size_t i = 0; i < size; ++i) { //копируются элементы из старой памяти в новую
                new_data[i] = data[i];
            }
            allocator_type().deallocate(data, capacity); //освобождается старая память
            data = new_data; //указатель на данные перенаправляется на новую память
            capacity *= 2; //вместимость увеличивается в два раза
        }
        data[size++] = value; //добавление нового элемента в контейнер
    }

    void print() const { //метод для вывода элементов контейнера в консоль
        for (size_t i = 0; i < size; ++i) { //цикл для вывода элементов
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

public:
    T* data; //указатель на данные
    size_t size; //размер контейнера
    size_t capacity; //вместимость контейнера
};