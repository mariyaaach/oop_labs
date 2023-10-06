#include "gtest/gtest.h"
#include "lib.h"


TEST(MoneyTest, AddTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    Money sum = m1 + m2;

    ASSERT_EQ(sum, Money("6912"));
}

TEST(MoneyTest, SubtractTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    Money difference = m1 - m2;

    ASSERT_EQ(difference, Money("5556"));
}

TEST(MoneyTest, GreaterThanTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    ASSERT_TRUE(m2 > m1);
}

TEST(MoneyTest, LessThanTest) {
    Money m1({1, 2, 3, 4});
    Money m2("5678");

    ASSERT_TRUE(m1 < m2);
}

TEST(MoneyTest, EqualTest) {
    Money m1({1, 2, 3, 4});
    Money m2("1234");

    ASSERT_TRUE(m1 == m2);
}

TEST(MoneyTest, InputTest) {
    Money m;
    m.input();

    ASSERT_EQ(m, Money("1234"));
}