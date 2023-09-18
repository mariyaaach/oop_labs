#include <gtest/gtest.h>
#include "lib.h"

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange
  int row = 1;
  int column = 3;

  // act
  int result = ChopTheChocolate(row, column);

  // assert
  EXPECT_EQ(result, 2);

}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange
  int row = 2;
  int column = 4;

  // act
  int result = ChopTheChocolate(row, column);

  // assert
  EXPECT_EQ(result, 4);
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange
  int row = 5;
  int column = 2;

  // act
  int result = ChopTheChocolate(row, column);

  // assert
  EXPECT_EQ(result, 5);
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  // arrange
  int row = -1;
  int column = 3;

  // act
  int result = ChopTheChocolate(row, column);

  // assert
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
  // arrange
  int row = 8;
  int column = 3;

  // act
  int result = ChopTheChocolate(row, column);

  // assert
  EXPECT_EQ(result, 9);
  }