#pragma once 

#include "npc.h" 

struct Knight : public NPC // Определение структуры Knight, наследующей от класса NPC
{
    Knight(int x, int y,std::string &_name); // Объявление конструктора класса Knight с параметрами x, y, _name
    Knight(std::ifstream &is,std::string &_name); // Объявление конструктора класса Knight с параметрами is, _name

    void print() override; // Объявление метода print, переопределенного из базового класса
    void save(std::ofstream &os) override; // Объявление переопределенного метода save класса Knight, принимающего ссылку на объект класса std::ofstream
    void get_name(std::ofstream &os) override; // Объявление переопределенного метода get_name класса Knight, принимающего ссылку на объект класса std::ofstream
    void accept(std::shared_ptr<NPC> attacker,Visitor& visitor); // Объявление метода accept класса Knight, принимающего указатель на объект класса NPC attacker и объект класса Visitor
    void attach(std::shared_ptr<IObserver> observer) override; // Объявление переопределенного метода attach класса Knight, принимающего указатель на объект интерфейса IObserver
    void detach(std::shared_ptr<IObserver> observer) override; // Объявление переопределенного метода detach класса Knight, принимающего указатель на объект интерфейса IObserver
    
    friend std::ostream &operator<<(std::ostream &os, Knight &knight); // Объявление дружественной функции перегруженного оператора << для класса Knight
};
