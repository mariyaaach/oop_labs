#include "dragon.h"
#include "knight.h"
#include "princess.h"

// Конструктор для класса Dragon
Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}

// Конструктор для класса Dragon, использующий входной поток
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

// Метод для обработки посещения другим NPC
bool Dragon::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Dragon>(this,[](Dragon*){}));
}

// Метод для вывода информации о драконе
void Dragon::print()
{
    std::cout << *this;
}

// Метод для обработки сражения с другим драконом
bool Dragon::fight(std::shared_ptr<Dragon> other) 
{
    fight_notify(other, false);
    return false;
}

// Метод для обработки сражения с рыцарем
bool Dragon::fight(std::shared_ptr<Knight> other) 
{
    fight_notify(other, false);
    return false;
}

// Метод для обработки сражения с принцессой
bool Dragon::fight(std::shared_ptr<Princess> other) 
{
    fight_notify(other, true);
    return false;
}

// Метод для сохранения состояния дракона в выходной поток
void Dragon::save(std::ostream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

// Перегруженный оператор вывода для класса Dragon
std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}
