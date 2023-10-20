#include "gtest/gtest.h"
#include "lib.h"


TEST(MoneyTest1, LessThanTest) {
    Money m1({1, 1, 1, 1});
    Money m2("5678");

    ASSERT_TRUE(m1 < m2);
}

TEST(MoneyTest2, SubtractTest) {
    Money m1({1, 1, 1, 1, 1});
    Money m2("5678");

    Money difference = m1 - m2;

    ASSERT_EQ(difference, Money("5433"));
}

TEST(MoneyTest3, GreaterThanTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    ASSERT_TRUE(m2 > m1);
}

TEST(MoneyTest4, LessThanTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5679");

    ASSERT_TRUE(m1 < m2);
}

TEST(MoneyTest5, GreaterThanTest) {
    Money m1({2, 2, 2, 2});
    Money m2("1111");

    ASSERT_TRUE(m1 > m2);
}

TEST(MoneyTest6, AddTest) {
    Money m1({1, 1, 1, 1});
    Money m2("2831");

    Money sum = m1 + m2;

    ASSERT_EQ(sum, Money("3942"));
}

TEST(MoneyTest7, SubtractTest) {
    Money m1({1, 1, 1, 1, 1});
    Money m2("5678");

    Money difference = m1 - m2;

    ASSERT_EQ(difference, Money("5433"));
}

TEST(MoneyTest8, GreaterThanTest) {
    Money m1({5, 7, 9, 1, 2, 3});
    Money m2("4345");

    ASSERT_TRUE(m2 < m1);
}

TEST(MoneyTest9, LessThanTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    ASSERT_TRUE(m1 < m2);
}


