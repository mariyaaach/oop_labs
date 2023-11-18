#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>

using namespace std;

struct Point {
private:
    double x;
    double y;

public:
    Point(double x, double y);

    static Point make_point(double x, double y);
    static double line_len(const Point& p1, const Point& p2); 

    double get_x() const noexcept;
    double get_y() const noexcept;
    void set_x(double x) noexcept;
    void set_y(double y) noexcept;

    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
    friend istream& operator>>(istream&, Point&);
    friend ostream& operator<<(ostream&, const Point&);

};

#endif