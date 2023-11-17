#include <gtest/gtest.h>
#include "container.h"
#include "factorial.h"

TEST(MyContainerTest1, PushBack) {
    // Arrange
    MyContainer<int, 5> container;

    // Act
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);

    // Assert
    EXPECT_EQ(container.size, 3);
    EXPECT_EQ(container.capacity, 5);
    EXPECT_EQ(container.data[0], 1);
    EXPECT_EQ(container.data[1], 2);
    EXPECT_EQ(container.data[2], 3);
}

TEST(MyContainerTest2, Print) {
    // Arrange
    MyContainer<int, 5> container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);

    testing::internal::CaptureStdout();

    // Act
    container.print();

    // Assert
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(MyMapTest, Factorial) {
    // Arrange
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMap;

    // Act
    for (int i = 0; i < 10; ++i) {
        myMap[i] = factorial(i);
    }

    // Assert
    EXPECT_EQ(myMap[0], 1);
    EXPECT_EQ(myMap[1], 1);
    EXPECT_EQ(myMap[2], 2);
    EXPECT_EQ(myMap[3], 6);
    EXPECT_EQ(myMap[4], 24);
    EXPECT_EQ(myMap[5], 120);
    EXPECT_EQ(myMap[6], 720);
    EXPECT_EQ(myMap[7], 5040);
    EXPECT_EQ(myMap[8], 40320);
    EXPECT_EQ(myMap[9], 362880);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
