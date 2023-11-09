#ifndef RHOMBUS_HPP_INCLUDED
#define RHOMBUS_HPP_INCLUDED

#include "Figure.h"

#include <iostream>

using namespace std;

class Rhombus: public Figure {
public:    
    Rhombus(const Point&, const Point&, const Point&, const Point&);
    operator double() const override;
    Point geom_center() const override;

    friend ostream& operator<<(ostream&, const Rhombus&);
    friend istream& operator>>(istream&, Rhombus&);
    friend bool operator==(const Rhombus&, const Rhombus&);

private:
    bool is_valid(const Point&, const Point&, const Point&, const Point&);
};


#endif