#include "knight.h"
#include "princess.h"
#include "dragon.h"

// Конструктор для класса Knight
Knight::Knight(int x, int y) : NPC(KnightType, x, y) {}

// Конструктор для класса Knight, использующий входной поток
Knight::Knight(std::istream &is) : NPC(KnightType, is) {}

// Метод для вывода информации о рыцаре
void Knight::print()
{
    std::cout << *this;
}

// Метод для обработки посещения другим NPC
bool Knight::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Knight>(this,[](Knight*){}));
}

// Метод для сохранения состояния рыцаря в выходной поток
void Knight::save(std::ostream &os)
{
    os << KnightType << std::endl;
    NPC::save(os);
}

// Метод для обработки сражения с драконом
bool Knight::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, true);
    return true;
}

// Метод для обработки сражения с другим рыцарем
bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

// Метод для обработки сражения с принцессой
bool Knight::fight(std::shared_ptr<Princess> other)
{
    fight_notify(other, false);
    return false;
}

// Перегруженный оператор вывода для класса Knight
std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}
