#include "observer.h" 
#include "npc.h" 

IObserver::~IObserver(){} // Определение деструктора для интерфейса IObserver

void ConsoleObserver::on_fight(NPC* attacker,NPC* defender, bool win) { // Определение функции on_fight класса ConsoleObserver, принимающей указатели на объекты класса NPC attacker и defender, а также флаг win
    if (win){ // Если win равно true
        std::cout << std::endl << "-------- Murder --------" << std::endl; // Вывод строки "-------- Murder --------" в стандартный поток вывода
        std::cout << "attaker -> "; // Вывод строки "attaker -> " в стандартный поток вывода
        attacker->print(); // Вызов метода print для объекта attacker
        std::cout << "defender -> "; // Вывод строки "defender -> " в стандартный поток вывода
        defender->print(); // Вызов метода print для объекта defender
    }
}

FileObserver::FileObserver(std::string &_filename) : filename(_filename){ // Определение конструктора класса FileObserver с параметром _filename, инициализирующего поле filename
    in.open(filename); // Открытие файла с именем filename
}

FileObserver::FileObserver(FileObserver &other) : FileObserver(other.filename){} // Определение конструктора копирования класса FileObserver, инициализирующего поле filename

FileObserver::FileObserver(FileObserver &&other) : FileObserver(other.filename){} // Определение конструктора перемещения класса FileObserver, инициализирующего поле filename

FileObserver::~FileObserver(){ // Определение деструктора класса FileObserver
    in.close(); // Закрытие файла
}

void FileObserver::on_fight(NPC* attacker,NPC* defender, bool win) { // Определение функции on_fight класса FileObserver, принимающей указатели на объекты класса NPC attacker и defender, а также флаг win
    if(in.is_open()){ // Если файл открыт
        if (win){ // Если win равно true
            in << std::endl << "-------- Murder --------" << std::endl; // Запись строки "-------- Murder --------" в файл
            in << "attaker -> "; // Запись строки "attaker -> " в файл
            attacker->get_name(in); // Вызов метода get_name для объекта attacker с параметром in
            in << "defender -> "; // Запись строки "defender -> " в файл
            defender->get_name(in); // Вызов метода get_name для объекта defender с параметром in
        }
    }
}
