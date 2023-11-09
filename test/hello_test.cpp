#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Pentagon.cpp"
#include "Hexagon.h"
#include "Hexagon.cpp"
#include "Rhombus.h"
#include "Rhombus.cpp"

#define INACCURACY 1e-5

TEST(constructor_test1, valid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2);

    EXPECT_NO_THROW(Diamond(p1, p2, p3, p4));
}

TEST(constructor_test2, invalid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, -1);

    EXPECT_THROW(Diamond(p1, p2, p3, p4), std::invalid_argument);
}

TEST(geom_center_test3, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Diamond test(p1, p2, p3, p4);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 4.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2.0 < INACCURACY);
}

TEST(operator_double_test4, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Diamond test(p1, p2, p3, p4);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 5.0 < INACCURACY);
}


TEST(constructor_test5, valid_points) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_NO_THROW(Hexagon(p1, p2, p3, p4, p5, p6));
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

TEST(geom_center_test7, normal) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon test(p1, p2, p3, p4, p5, p6);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - (-1.0) < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2 < INACCURACY);
}

TEST(operator_double_test8, normal) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon test(p1, p2, p3, p4, p5, p6);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 83.1384 < INACCURACY);
}

TEST(constructor_test9, valid_points) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01);

    EXPECT_NO_THROW(Pentagon(p1, p2, p3, p4, p5));
}

TEST(constructor_test10, invalid_points) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(18.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 3.01);

    EXPECT_THROW(Pentagon(p1, p2, p3, p4, p5), std::invalid_argument);
}

TEST(geom_center_test11, normal) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01);

    Pentagon test(p1, p2, p3, p4, p5);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 30.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - (-0.01) < INACCURACY);
}

TEST(operator_double_test12, normal) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01); 

    Pentagon test(p1, p2, p3, p4, p5);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 9.62676 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 