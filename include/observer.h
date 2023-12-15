#pragma once 

#include <iostream> 
#include <memory> 
#include <fstream> 

class NPC; // Объявление класса NPC

class IObserver{
public:
    IObserver() = default; // Конструктор по умолчанию
    virtual ~IObserver(); // Виртуальный деструктор
    virtual void on_fight(NPC*attacker,NPC* defender, bool win) = 0; // Виртуальная функция on_fight, принимающая указатели на объекты класса NPC attacker, defender и флаг win
};

class ConsoleObserver: public IObserver { // Определение класса ConsoleObserver, наследующего от IObserver
public:
    ConsoleObserver() = default; // Конструктор по умолчанию
    void on_fight(NPC* attacker,NPC* defender, bool win) override; // Переопределенная функция on_fight
};

class FileObserver: public IObserver { // Определение класса FileObserver, наследующего от IObserver
public:
    std::ofstream in; // Поток вывода в файл
    std::string filename; // Имя файла
    FileObserver() = default; // Конструктор по умолчанию
    FileObserver(std::string &_filename); // Конструктор с параметром-ссылкой на строку
    FileObserver(FileObserver &other); // Конструктор копирования
    FileObserver(FileObserver &&other); // Конструктор перемещения
    ~FileObserver(); // Деструктор
    void on_fight(NPC* attacker, NPC* defender, bool win) override; // Переопределенная функция on_fight
};
