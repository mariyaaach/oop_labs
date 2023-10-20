#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Money {
public:
    size_t length; //  Длина массива 
    unsigned char* amount; // Указатель на массив

public:
    // Конструкторы
    Money();
    Money(initializer_list<unsigned char> initList);
    Money(const string& str);
    Money(const Money& other);
    Money(Money&& other) noexcept; 

    // Деструктор
    ~Money();

    // Операторы
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    // Методы
    void print() const;
    void input();


};