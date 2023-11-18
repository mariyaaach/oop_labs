#include <iostream>
#include "Rhombus.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Vector.h"
#include <cmath>

using namespace std;

int main() {
    //создание объектов Rhombus, t0 и t1, с использованием конструктора, который принимает 4 точки
    Rhombus* t0 = new Rhombus(Point(4, 4), Point(7, 2), Point(4, 0), Point(1, 2));
    Rhombus* t1 = new Rhombus(Point(3, 0), Point(0, -2), Point(-3, 0), Point(0, 2));
    
    //создание объекта Pentagon, s0, с использованием конструктора, который принимает 5 точек
    Pentagon* s0 = new Pentagon(Point(0, 100), 
                                Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)),
                                Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
                                Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
                                Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    
    //создание вектора v с типом Figure* и добавление объектов t0, t1 и s0 в вектор
    Vector<Figure*> v = {t0, t1, s0};
    
    //инициализация переменной area для хранения общей площади фигур
    double area = 0;

    //итерация через все элементы вектора и добавление их площади к переменной area
    for (size_t i = 0; i < v.get_size(); ++i) {
        area += static_cast<double>(*v[i]);
    }

    //вывод общей площади фигур в консоль
    cout << area << endl;
}
