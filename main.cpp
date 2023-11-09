#include <iostream>

#include "Rhombus.h"
#include "Hexagon.h"
#include "Pentagon.h"
#include "Vector.h"
#include <cmath>

using namespace std;

int main() {
    Rhombus* t0 = new Rhombus(Point(4, 4), Point(7, 2), Point(4, 0), Point(1, 2));
    Rhombus* t1 = new Rhombus(Point(3, 0), Point(0, -2), Point(-3, 0), Point(0, 2));
    Pentagon* s0 = new Pentagon(Point(0, 100), 
                                Point(sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)),
                                Point(25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
                                Point(-25 * (-sqrt(2) + sqrt(10)) * sqrt(5 + sqrt(5)) / 2.0, -25 - 25 * sqrt(5)),
                                Point(-sqrt(6250 + 1250 * sqrt(5)), -25 + 25 * sqrt(5)));
    Vector<Figure*> v = {t0, t1, s0};
    double area = 0;

    for (size_t i = 0; i < v.get_size(); ++i) {
        area += static_cast<double>(*v[i]);
    }

    cout << area << endl;
}