#ifndef PENTAGON_HPP_INCLUDED
#define PENTAGON_HPP_INCLUDED

#include "Figure.h"
#include <iostream>

using namespace std;

class Pentagon: public Figure {
public:    
    Pentagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    );
    operator double() const override;
    Point geom_center() const override;

    friend std::ostream& operator<<(ostream&, const Pentagon&);
    friend std::istream& operator>>(istream&, Pentagon&);
    friend bool operator==(const Pentagon&, const Pentagon&);


private:
    bool is_valid(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5
    ) noexcept;
};


#endif