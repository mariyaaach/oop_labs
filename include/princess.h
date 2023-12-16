#pragma once
#include "npc.h" 

// Определение класса Princess, унаследованного от класса NPC
struct Princess : public NPC
{
    // Конструкторы
    Princess(int x, int y);
    Princess(std::istream &is);

    // Переопределение виртуальных методов базового класса NPC
    void print() override;
    void save(std::ostream &os) override;
    bool fight(std::shared_ptr<Dragon> other) override;
    bool fight(std::shared_ptr<Knight> other) override;
    bool fight(std::shared_ptr<Princess> other) override;
    bool accept(std::shared_ptr<NPC> visitor) override;

    friend std::ostream &operator<<(std::ostream &os, Princess &knight); // Дружественная функция для вывода объектов класса Princess
};
