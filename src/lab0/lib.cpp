#include "lib.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Конструкторы класса Money

// Конструктор по умолчанию
Money::Money() : length(0), amount(nullptr) {}

// Конструктор с использованием списка инициализации
Money::Money(initializer_list<unsigned char> initList) : length(initList.size()) {
    amount = new unsigned char[length]; // Выделение памяти для массива amount

    size_t i = 0;
    for (auto it = initList.begin(); it != initList.end(); ++it, ++i) {
        amount[i] = *it; // Заполнение массива amount значениями из списка инициализации
    }
}

// Конструктор с использованием строки
Money::Money(const string& str) : length(str.length()) {
    amount = new unsigned char[length]; // Выделение памяти для массива amount

    size_t i = 0;
    for (auto it = str.rbegin(); it != str.rend(); ++it, ++i) {
        amount[i] = *it - '0'; // Заполнение массива amount значениями из строки, преобразованными в числа
    }
}

// Деструктор класса Money
Money::~Money() {
    delete[] amount; // Освобождение памяти, выделенной для массива amount
}

// Перегрузка оператора сложения
Money Money::operator+(const Money& other) const {
    size_t maxLength = max(length, other.length); // Определение максимальной длины суммируемых сумм
    size_t minLength = min(length, other.length); // Определение минимальной длины суммируемых сумм

    Money result; // Создание нового объекта Money для хранения результата сложения
    result.length = maxLength; // Установка длины результата
    result.amount = new unsigned char[maxLength]; // Выделение памяти для массива amount результата

    unsigned char carry = 0; // Переменная для хранения переноса
    for (size_t i = 0; i < minLength; i++) {
        unsigned int sum = amount[i] + other.amount[i] + carry; // Сложение цифр сумм и переноса
        result.amount[i] = sum % 10; // Запись последней цифры суммы в результат
        carry = sum / 10; // Определение нового значения переноса
    }

    const unsigned char* longerAmount = (length > other.length) ? amount : other.amount; // Определение массива с большей длиной
    for (size_t i = minLength; i < maxLength; i++) {
        unsigned int sum = longerAmount[i] + carry; // Сложение цифры суммы с переносом
        result.amount[i] = sum % 10; // Запись последней цифры суммы в результат
        carry = sum / 10; // Определение нового значения переноса
    }

    if (carry > 0) {
        result.length++; // Увеличение длины результата
        unsigned char* tempAmount = new unsigned char[result.length]; // Выделение временной памяти для нового массива amount

        memcpy(tempAmount, result.amount, (result.length - 1) * sizeof(unsigned char)); // Копирование данных из старого массива в новый
        tempAmount[result.length - 1] = carry; // Добавление последней цифры переноса в конец нового массива

        delete[] result.amount; // Освобождение памяти, выделенной для старого массива amount
        result.amount = tempAmount;
    }

    return result;
}

// Оператор вычитания
Money Money::operator-(const Money& other) const {
    // Проверяем, если текущая сумма меньше суммы, которую нужно вычесть
    if (*this < other) {
        throw logic_error("It is impossible to deduct a larger amount from a smaller one");
    }

    // Создаем новый объект Money для хранения результата
    Money result;
    result.length = length;
    result.amount = new unsigned char[length];

    unsigned char borrow = 0;
    for (size_t i = 0; i < length; i++) {
        // Вычисляем разность между текущими цифрами сумм
        int diff = amount[i] - borrow - ((i < other.length) ? other.amount[i] : 0);
        if (diff < 0) {
            // Если разность отрицательная, заем 10 у следующей цифры
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        // Сохраняем разность в объекте-результате Money
        result.amount[i] = diff;
    }

    // Удаляем ведущие нули из результата
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

    // Сравниваем цифры, начиная с наиболее значимой цифры
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
    // Возвращаем true, если текущая сумма меньше другой суммы
    return !(*this > other) && !(*this == other);
}

// Оператор равно
bool Money::operator==(const Money& other) const {
    if (length != other.length) {
        return false;
    }

    // Сравниваем каждую цифру сумм
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
        // Преобразуем тип unsigned char в int для печати
        cout << static_cast<int>(amount[i]);
    }
    cout << endl;
}

// Метод для ввода денежной суммы с клавиатуры
void Money::input() {
    string str;
    cout << "Enter amount: ";
    cin >> str;

    // Устанавливаем длину суммы и выделяем память
    length = str.length();
    amount = new unsigned char[length];

    size_t i = 0;
    // Преобразуем каждый символ строки в соответствующую цифру
    for (auto it = str.rbegin(); it != str.rend(); ++it, ++i) {
        amount[i] = *it - '0';
    }
}