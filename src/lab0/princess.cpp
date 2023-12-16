#include "princess.h"
#include "dragon.h"
#include "knight.h"

// Конструктор для класса Princess
Princess::Princess(int x, int y) : NPC(PrincessType, x, y) {}

// Конструктор для класса Princess, использующий входной поток
Princess::Princess(std::istream &is) : NPC(PrincessType, is) {}

// Метод для обработки посещения другим NPC
bool Princess::accept(std::shared_ptr<NPC> visitor){
    return visitor->fight(std::shared_ptr<Princess>(this,[](Princess*){}));
}

// Метод для вывода информации о принцессе
void Princess::print()
{
    std::cout << *this;
}

// Метод для сохранения состояния принцессы в выходной поток
void Princess::save(std::ostream &os)
{
    os << PrincessType << std::endl;
    NPC::save(os);
}

// Метод для обработки сражения с драконом
bool Princess::fight(std::shared_ptr<Dragon> other)
{
    fight_notify(other, false);
    return true;
}

// Метод для обработки сражения с рыцарем
bool Princess::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return true;
}

// Метод для обработки сражения с другой принцессой
bool Princess::fight(std::shared_ptr<Princess> other)
{
    fight_notify(other, false);
    return true;
}

// Перегруженный оператор вывода для класса Princess
std::ostream &operator<<(std::ostream &os, Princess &princess)
{
    os << "princess: " << *static_cast<NPC *>(&princess) << std::endl;
    return os;
}
