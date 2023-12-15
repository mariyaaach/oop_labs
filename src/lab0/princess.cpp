#include "princess.h" 
#include "dragon.h" 
#include "knight.h" 
#include <algorithm> 

Princess::Princess(int x, int y,std::string &_name) :  NPC(PrincessType, x, y, _name) {} // Определение конструктора класса Princess с параметрами x, y, _name, вызывающего конструктор базового класса NPC с параметрами PrincessType, x, y, _name

Princess::Princess(std::ifstream &is,std::string &_name) : NPC(PrincessType, is, _name) {} // Определение конструктора класса Princess с параметрами is, _name, вызывающего конструктор базового класса NPC с параметрами PrincessType, is, _name

Princess::~Princess() {} // Определение деструктора класса Princess

void Princess::print() // Определение функции print класса Princess
{
    std::cout << *this; // Вывод объекта класса Princess в стандартный поток вывода
}

void Princess::save(std::ofstream &os){ // Определение функции save класса Princess, принимающей ссылку на объект класса std::ofstream
    os << PrincessType << std::endl; // Запись PrincessType в поток os
    NPC::save(os); // Вызов функции save базового класса NPC с параметром os
}

void Princess::get_name(std::ofstream &os){ // Определение функции get_name класса Princess, принимающей ссылку на объект класса std::ofstream
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl; // Запись имени, координат x и y в поток os
}

void Princess::attach(std::shared_ptr<IObserver> observer) { // Определение функции attach класса Princess, принимающей указатель на объект интерфейса IObserver
    NPC::observers.push_back(observer); // Добавление объекта observer в вектор observers базового класса NPC
}

void Princess::detach(std::shared_ptr<IObserver> observer) { // Определение функции detach класса Princess, принимающей указатель на объект интерфейса IObserver
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer)); // Удаление объекта observer из вектора observers базового класса NPC при помощи функции std::find и std::vector::erase
}

std::ostream &operator<<(std::ostream &os, Princess &princess) // Определение перегруженного оператора << для класса Princess
{
    os << "princess: " << *static_cast<NPC*>(&princess) << std::endl; // Вывод строки "princess: " и объекта princess базового класса NPC в стандартный поток вывода
    return os; // Возврат ссылки на стандартный поток вывода
}
