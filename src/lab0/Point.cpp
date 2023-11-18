#include "Point.h"
#include <cmath>

Point::Point(double x, double y): x(x), y(y) {} //конструктор класса Point с инициализацией координат x и y

Point Point::make_point(double x, double y) { //метод make_point для создания объекта класса Point
    return Point(x, y); //возвращает новый объект класса Point с координатами x и y
}

double Point::get_x() const noexcept{ //метод для получения значения координаты x
    return x; //возвращает значение координаты x
}

double Point::get_y() const noexcept{ //метод для получения значения координаты y
    return y; //возвращает значение координаты y
}

void Point::set_x(double x) noexcept { //метод для установки значения координаты x
    this->x = x; //устанавливает значение координаты x
}

void Point::set_y(double y) noexcept { //метод для установки значения координаты y
    this->y = y; //устанавливает значение координаты y
}

double Point::line_len(const Point& p1, const Point& p2) { // метод для вычисления длины отрезка между двумя точками
    double x1 = p1.get_x(); //получение координаты x первой точки
    double x2 = p2.get_x(); //получение координаты x второй точки
    
    double y1 = p1.get_y(); //получение координаты y первой точки
    double y2 = p2.get_y();  //получение координаты y второй точки
    
    return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2)); //вычисление и возврат длины отрезка между двумя точками
}

bool operator==(const Point& lhs, const Point& rhs) { //перегрузка оператора сравнения равенства для объектов класса Point

    double inaccuracy = 1e-5; //задание погрешности для сравнения

    if (std::abs(lhs.x - rhs.x) < inaccuracy && std::abs(lhs.y - lhs.y) < inaccuracy) {  // сравнение координат x и y с учетом погрешности
        return true; //если координаты равны с учетом погрешности, возвращается true
    }

    return false; // 
}

bool operator!=(const Point& lhs, const Point& rhs) { //перегрузка оператора сравнения неравенства для объектов класса Point
    return !(lhs == rhs); //возвращает результат противоположного сравнения равенства
}

std::istream& operator>>(std::istream& is, Point& p) { //перегрузка оператора ввода из потока для объектов класса Point
    is >> p.x >> p.y; //считывание значений координат из потока
    return is; //возврат ссылки на поток ввода
}

std::ostream& operator<<(std::ostream& os, const Point& p) { //перегрузка оператора вывода в поток для объектов класса Point
    os << '(' << p.x << ',' << p.y << ')'; //вывод значений координат в виде (x,y)
    return os; //возврат ссылки на поток вывода
}