#include "npc.h"

// Конструктор класса NPC
NPC::NPC(NpcType t, int _x, int _y) : type(t), x(_x), y(_y) {}
// Конструктор класса NPC, использующий входной поток
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
}

// Метод для подписки на наблюдателя
void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
    observers.push_back(observer);
}

// Метод для уведомления наблюдателей о сражении
void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &o : observers)
        o->on_fight(std::shared_ptr<NPC>(this, [](NPC *) {}), defender, win);
}

// Метод для проверки, находится ли NPC рядом с другим NPC
bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance)
{
    auto [other_x, other_y] = other->position();

    std::lock_guard<std::mutex> lck(mtx);
    if ((std::pow(x - other_x, 2) + std::pow(y - other_y, 2)) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

// Метод для получения типа NPC
NpcType NPC::get_type()
{
    std::lock_guard<std::mutex> lck(mtx);
    return type;
}

// Метод для получения позиции NPC
std::pair<int, int> NPC::position()
{
    std::lock_guard<std::mutex> lck(mtx);
    return {x, y};
}

// Метод для сохранения состояния NPC в поток вывода
void NPC::save(std::ostream &os)
{
    os << x << std::endl;
    os << y << std::endl;
}

// Перегруженный оператор вывода для класса NPC
std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "{ x:" << npc.x << ", y:" << npc.y << "} ";
    return os;
}

// Метод для перемещения NPC
void NPC::move(int shift_x, int shift_y, int max_x, int max_y)
{
    std::lock_guard<std::mutex> lck(mtx);

    if ((x + shift_x >= 0) && (x + shift_x <= max_x))
        x += shift_x;
    if ((y + shift_y >= 0) && (y + shift_y <= max_y))
        y += shift_y;
}

// Метод для проверки, жив ли NPC
bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

// Метод для пометки NPC как мертвого
void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}
