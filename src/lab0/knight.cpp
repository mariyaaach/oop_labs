#include "knight.h" 
#include "princess.h" 
#include "dragon.h" 
#include <algorithm>

Knight::Knight(int x, int y,std::string &_name) : NPC(KnightType, x, y,_name) {} // Определение конструктора класса Knight с параметрами x, y, _name, вызывающего конструктор базового класса NPC с параметрами KnightType, x, y, _name

Knight::Knight(std::ifstream &is,std::string &_name) : NPC(KnightType, is, _name) {} // Определение конструктора класса Knight с параметрами is, _name, вызывающего конструктор базового класса NPC с параметрами KnightType, is, _name

void Knight::print() // Определение функции print класса Knight
{
    std::cout << *this; // Вывод объекта класса Knight в стандартный поток вывода
}

void Knight::attach(std::shared_ptr<IObserver> observer) { // Определение функции attach класса Knight, принимающей указатель на объект интерфейса IObserver
    NPC::observers.push_back(observer); // Добавление объекта observer в вектор observers базового класса NPC
}

void Knight::detach(std::shared_ptr<IObserver> observer) { // Определение функции detach класса Knight, принимающей указатель на объект интерфейса IObserver
    NPC::observers.erase(std::find(NPC::observers.begin(), NPC::observers.end(), observer)); // Удаление объекта observer из вектора observers базового класса NPC при помощи функции std::find и std::vector::erase
}

void Knight::save(std::ofstream &os) // Определение функции save класса Knight, принимающей ссылку на объект класса std::ofstream
{
    os << KnightType << std::endl; // Запись KnightType в поток os
    NPC::save(os); // Вызов функции save базового класса NPC с параметром os
}

void Knight::get_name(std::ofstream &os){ // Определение функции get_name класса Knight, принимающей ссылку на объект класса std::ofstream
    os << this->name << " " << "{x: " << this->x << "; y:" << this->y << "}" << std::endl; // Запись имени, координат x и y в поток os
}

std::ostream &operator<<(std::ostream &os, Knight &knight) // Определение перегруженного оператора << для класса Knight
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl; // Вывод строки "knight: " и объекта knight базового класса NPC в стандартный поток вывода
    return os; // Возврат ссылки на стандартный поток вывода
}
