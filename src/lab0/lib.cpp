#include "lib.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Конструкторы
Money::Money() : length(0), amount(nullptr) {}

Money::Money(initializer_list<unsigned char> initList) : length(initList.size()) {
    amount = new unsigned char[length];

    size_t i = 0;
    for (auto it = initList.begin(); it != initList.end(); ++it, ++i) {
        amount[i] = *it;
    }
}

Money::Money(const string& str) : length(str.length()) {
    amount = new unsigned char[length];

    size_t i = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it, ++i) {
        amount[i] = *it - '0';
    }
}

// Деструктор
Money::~Money() {
    delete[] amount;
}

// Оператор сложения
Money Money::operator+(const Money& other) const {
    size_t maxLength = max(length, other.length);
    size_t minLength = min(length, other.length);

    Money result;
    result.length = maxLength;
    result.amount = new unsigned char[maxLength];

    unsigned char carry = 0;
    for (size_t i = 0; i < minLength; i++) {
        unsigned int sum = amount[i] + other.amount[i] + carry;
        result.amount[i] = sum % 10;
        carry = sum / 10;
    }

    const unsigned char* longerAmount = (length > other.length) ? amount : other.amount;
    for (size_t i = minLength; i < maxLength; i++) {
        unsigned int sum = longerAmount[i] + carry;
        result.amount[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.length++;
        unsigned char* tempAmount = new unsigned char[result.length];

        memcpy(tempAmount, result.amount, (result.length - 1) * sizeof(unsigned char));
        tempAmount[result.length - 1] = carry;

        delete[] result.amount;
        result.amount = tempAmount;
    }

    return result;
}

// Оператор вычитания
Money Money::operator-(const Money& other) const {
    if (*this < other) {
        throw logic_error("Cannot subtract larger amount from smaller amount");
    }

    Money result;
    result.length = length;
    result.amount = new unsigned char[length];

    unsigned char borrow = 0;
    for (size_t i = 0; i < length; i++) {
        int diff = amount[i] - borrow - ((i < other.length) ? other.amount[i] : 0);
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.amount[i] = diff;
    }

    while (result.length > 1 && result.amount[result.length - 1] == 0) {
        result.length--;
    }

    return result;
}

// Оператор больше
bool Money::operator>(const Money& other) const {
    if (length > other.length) {
        return true;
    } else if (length < other.length) {
        return false;
    }

    for (size_t i = length; i > 0; i--) {
        if (amount[i - 1] > other.amount[i - 1]) {
            return true;
        } else if (amount[i - 1] < other.amount[i - 1]) {
            return false;
        }
    }

    return false;
}

// Оператор меньше
bool Money::operator<(const Money& other) const {
    return !(*this > other) && !(*this == other);
}

// Оператор равно
bool Money::operator==(const Money& other) const {
    if (length != other.length) {
        return false;
    }

    for (size_t i = 0; i < length; i++) {
        if (amount[i] != other.amount[i]) {
            return false;
        }
    }

    return true;
}

// Метод для печати денежной суммы
void Money::print() const {
    for (int i = length - 1; i >= 0; i--) {
        cout << static_cast<int>(amount[i]);
    }
    cout << endl;
}

// Метод для ввода денежной суммы с клавиатуры
void Money::input() {
    string str;
    cout << "Enter monetary amount: ";
    cin >> str;

    length = str.length();
    amount = new unsigned char[length];

    size_t i = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it, ++i) {
        amount[i] = *it - '0';
    }
}