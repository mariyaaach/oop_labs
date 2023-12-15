#pragma once 

#include "npc.h" 

struct Princess : public NPC // Определение структуры Princess, наследующей от класса NPC
{
    Princess(int x, int y,std::string &_name); // Объявление конструктора класса Princess с параметрами x, y, _name
    Princess(std::ifstream &is,std::string &_name); // Объявление конструктора класса Princess с параметрами is, _name
    ~Princess(); // Объявление деструктора класса Princess

    void print() override; // Переопределенный метод print
    void save(std::ofstream &os) override; // Переопределенный метод save

    void get_name(std::ofstream &os) override; // Переопределенный метод get_name

    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor); // Метод accept
    void attach(std::shared_ptr<IObserver> observer) override; // Переопределенный метод attach
    void detach(std::shared_ptr<IObserver> observer) override; // Переопределенный метод detach

    friend std::ostream &operator<<(std::ostream &os, Princess &princess); // Объявление дружественной функции перегруженного оператора << для класса Princess
};
