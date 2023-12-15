#include "npc.h" 

NPC::NPC(NpcType t, int _x, int _y,std::string &_name) : type(t), x(_x), y(_y), name(_name) {} // Определение конструктора класса NPC с параметрами t, _x, _y, _name, инициализирующего поля type, x, y, name

NPC::NPC(NpcType t,std::ifstream &is,std::string &_name): type(t), name(_name) // Определение конструктора класса NPC с параметрами t, is, _name, инициализирующего поля type, name
{
    is >> x; // Считывание значения x из потока is
    is >> y; // Считывание значения y из потока is
}

NPC::NPC(NPC& other) : type(other.type), x(other.x),y(other.y){} // Определение конструктора копирования класса NPC, инициализирующего поля type, x, y

NPC::NPC(NPC* other) : type(other->type), x(other->x),y(other->y){} // Определение конструктора класса NPC, принимающего указатель на объект другого класса NPC, инициализирующего поля type, x, y

NPC::~NPC(){} // Определение деструктора класса NPC

void NPC::notify(NPC* attacker, bool win) { // Определение функции notify класса NPC, принимающей указатель на объект класса NPC attacker и флаг win
    if (win) { // Если win равно true
        for (auto &elem : NPC::observers) { // Цикл по всем элементам в векторе observers класса NPC
            elem->on_fight(attacker,this, win); // Вызов метода on_fight для каждого наблюдателя с параметрами attacker, this и win
        }
    }
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const // Определение функции is_close класса NPC, принимающей указатель на объект класса NPC other и значение distance, возвращающей булево значение
{
    if (std::pow(x - other->x, 2) + std::pow(y - other->y, 2) <= std::pow(distance, 2)) // Если квадрат разницы координат x и y меньше или равен квадрату distance
        return true; // Возвращается true
    else // Иначе
        return false; // Возвращается false
}

void NPC::save(std::ofstream &os) // Определение функции save класса NPC, принимающей ссылку на объект класса std::ofstream
{
    os << x << std::endl; // Запись значения x в поток os
    os << y << std::endl; // Запись значения y в поток os
}

std::ostream &operator<<(std::ostream &os, NPC &npc) // Определение перегруженного оператора << для класса NPC
{
    os << "name = " << npc.name << " { x:" << npc.x << ", y:" << npc.y << "} "; // Вывод строки "name = ", имени, координат x и y объекта npc в стандартный поток вывода
    return os; // Возврат ссылки на стандартный поток вывода
}
