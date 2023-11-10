#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Rhombus.h"
#include "Point.h"
#include <cmath>


#define INACCURACY 1e-5

TEST(constructor_test1, valid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2);

    EXPECT_NO_THROW(Rhombus(p1, p2, p3, p4));
}

TEST(constructor_test2, invalid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, -1);

    EXPECT_THROW(Rhombus(p1, p2, p3, p4), std::invalid_argument);
}

TEST(geom_center_test3, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Rhombus test(p1, p2, p3, p4);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 4.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2.0 < INACCURACY);
}

TEST(operator_double_test4, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Rhombus test(p1, p2, p3, p4);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 5.0 < INACCURACY);
}


TEST(constructor_test6, invalid_points) {
    Point p1(1, 4);
    Point p2(-3, 7);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_THROW(Hexagon(p1, p2, p3, p4, p5, p6), std::invalid_argument);
}

TEST(constructor_test8, valid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2);

    EXPECT_NO_THROW(Rhombus(p1, p2, p3, p4));
}


