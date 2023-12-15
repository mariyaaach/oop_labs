#pragma once 

#include <iostream> 
#include <memory> 
#include <cstring> 
#include <string> 
#include <random> 
#include <fstream> 
#include <set> 
#include <math.h>
#include "observer.h"

class NPC; // Объявление класса NPC
class Princess; // Объявление класса Princess
class Dragon; // Объявление класса Dragon
class Knight; // Объявление класса Knight
using set_t = std::set<std::shared_ptr<NPC>>; // Определение псевдонима типа для множества умных указателей на объекты класса NPC

enum NpcType {Unknown, PrincessType, DragonType, KnightType}; // Определение перечисления для типов NPC

class Visitor; // Объявление класса Visitor

class NPC{
public:
    NpcType type; // Поле для хранения типа NPC
    int x{0}, y{0}; // Поля для хранения координат x и y
    std::string name; // Поле для хранения имени
    std::vector<std::shared_ptr<IObserver>> observers; // Вектор умных указателей на объекты класса IObserver

    NPC(NpcType t, int _x, int _y,std::string &_name); // Объявление конструктора класса NPC с параметрами t, _x, _y, _name
    NPC(NpcType t,std::ifstream &is,std::string &_name); // Объявление конструктора класса NPC с параметрами t, is, _name
    NPC(NPC& other); // Объявление конструктора копирования класса NPC
    NPC(NPC* other); // Объявление конструктора класса NPC с параметром-указателем на объект другого класса NPC
    virtual ~NPC(); // Виртуальный деструктор класса NPC

    bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const; // Объявление метода is_close класса NPC, возвращающего булево значение, принимающего умный указатель на объект класса NPC other и значение distance
    void notify(NPC* attacker, bool win); // Объявление метода notify класса NPC, принимающего указатель на объект класса NPC attacker и флаг win

    virtual void get_name(std::ofstream &os){}; // Виртуальный метод get_name класса NPC, принимающий ссылку на объект класса std::ofstream
    virtual void accept(std::shared_ptr<NPC> attacker,Visitor& visitor){}; // Виртуальный метод accept класса NPC, принимающий умный указатель на объект класса NPC attacker и объект класса Visitor
    virtual void attach(std::shared_ptr<IObserver> observer){}; // Виртуальный метод attach класса NPC, принимающий умный указатель на объект интерфейса IObserver
    virtual void detach(std::shared_ptr<IObserver> observer){}; // Виртуальный метод detach класса NPC, принимающий умный указатель на объект интерфейса IObserver
    virtual void print(){}; // Виртуальный метод print класса NPC
    virtual void save(std::ofstream &os); // Виртуальный метод save класса NPC, принимающий ссылку на объект класса std::ofstream

    friend std::ostream &operator<<(std::ostream &os, NPC &npc); // Объявление дружественной функции перегруженного оператора << для класса NPC
};
