#include "container.h"
#include "factorial.h"
#include <iostream>
#include <map>


int main() {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMap;
    //cоздание экземпляра std::map с созданным аллокатором
    //rлючами в контейнере будут числа от 0 до 9, значениями - факториалы ключей
    for (int i = 0; i < 10; ++i) {
        myMap[i] = factorial(i); //вычисление факториала числа i и добавление значения в контейнер
    }
    for (const auto& pair : myMap) {
        //вывод на экран всех значений (ключ и значение разделены пробелом), хранящихся в контейнере
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    MyContainer<int, 5> myContainer;
    // создание экземпляра своего контейнера для хранения int с размером 5 и собственным аллокатором
    for (int i = 0; i < 10; ++i) {
        myContainer.push_back(i); //добавление элемента в контейнер
    }
    myContainer.print(); //вывод на экран всех элементов контейнера
    return 0;
}