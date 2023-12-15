#pragma once 

#include "npc.h" 

struct Dragon : public NPC // Определение структуры Dragon, наследующей от класса NPC
{
    Dragon(int x, int y,std::string &_name); // Объявление конструктора класса Dragon с параметрами x, y, _name
    Dragon(std::ifstream &is,std::string &_name); // Объявление конструктора класса Dragon с параметрами is, _name

    void print() override; // Объявление метода print, переопределенного из базового класса

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor); // Объявление метода accept класса Dragon, принимающего указатель на объект класса NPC attacker и объект класса Visitor

    void get_name(std::ofstream &os) override; // Объявление переопределенного метода get_name класса Dragon, принимающего ссылку на объект класса std::ofstream

    void attach(std::shared_ptr<IObserver> observer) override; // Объявление переопределенного метода attach класса Dragon, принимающего указатель на объект интерфейса IObserver
    void detach(std::shared_ptr<IObserver> observer) override; // Объявление переопределенного метода detach класса Dragon, принимающего указатель на объект интерфейса IObserver

    void save(std::ofstream &os) override; // Объявление переопределенного метода save класса Dragon, принимающего ссылку на объект класса std::ofstream

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon); // Объявление дружественной функции перегруженного оператора << для класса Dragon
};
