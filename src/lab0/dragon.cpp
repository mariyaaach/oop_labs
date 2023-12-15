#include "dragon.h" 
#include "knight.h" 
#include "princess.h" 
#include <algorithm> 

Dragon::Dragon(int x, int y,std::string &_name) : NPC(DragonType, x, y, _name) {} // Определение конструктора класса Dragon с параметрами x, y, _name, вызывающего конструктор базового класса NPC с параметрами DragonType, x, y, _name

Dragon::Dragon(std::ifstream &is,std::string &_name) : NPC(DragonType, is, _name) {} // Определение конструктора класса Dragon с параметрами is, _name, вызывающего конструктор базового класса NPC с параметрами DragonType, is, _name

void Dragon::print() // Определение функции print класса Dragon
{
    std::cout << *this; // Вывод объекта класса Dragon в стандартный поток вывода
}

void Dragon::attach(std::shared_ptr<IObserver> observer) { // Определение функции attach класса Dragon, принимающей указатель на объект интерфейса IObserver
    NPC::observers.push_back(observer); // Добавление объекта observer в вектор observers базового класса NPC
}

void Dragon::detach(std::shared_ptr<IObserver> observer) { // Определение функции detach класса Dragon, принимающей указатель на объект интерфейса IObserver
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer)); // Удаление объекта observer из вектора observers базового класса NPC при помощи функции std::find и std::vector::erase
}

void Dragon::save(std::ofstream &os)  // Определение функции save класса Dragon, принимающей ссылку на объект класса std::ofstream
{
    os << DragonType << std::endl; // Запись DragonType в поток os
    NPC::save(os); // Вызов функции save базового класса NPC с параметром os
}

void Dragon::get_name(std::ofstream &os){ // Определение функции get_name класса Dragon, принимающей ссылку на объект класса std::ofstream
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl; // Запись имени, координат x и y в поток os
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon) // Определение перегруженного оператора << для класса Dragon
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl; // Вывод строки "dragon: " и объекта dragon базового класса NPC в стандартный поток вывода
    return os; // Возврат ссылки на стандартный поток вывода
}
