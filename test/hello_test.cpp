#include <gtest/gtest.h>
#include "lib.h"

TEST(ExampleOfStandartUsageTest1, BasicAssertions) {
  // arrange
  int rowOfChocolate = 1;
  int columnOfChocolate = 3;

  // act
  int result = chopTheChocolate(rowOfChocolate, columnOfChocolate);

  // assert
  EXPECT_EQ(result, 2);

}

TEST(ExampleOfStandartUsageTest2, BasicAssertions) {
  // arrange
  int rowOfChocolate = 2;
  int columnOfChocolate = 4;

  // act
  int result = chopTheChocolate(rowOfChocolate, columnOfChocolate);

  // assert
  EXPECT_EQ(result, 4);
}

TEST(ExampleOfStandartUsageTest3, BasicAssertions) {
  // arrange
  int rowOfChocolate = 5;
  int columnOfChocolate = 2;

  // act
  int result = chopTheChocolate(rowOfChocolate, columnOfChocolate);

  // assert
  EXPECT_EQ(result, 5);
}

TEST(ExampleOfStandartUsageTest4, BasicAssertions) {
  // arrange
  int rowOfChocolate = -1;
  int columnOfChocolate = 3;

  // act
  int result = chopTheChocolate(rowOfChocolate, columnOfChocolate);

  // assert
  EXPECT_EQ(result, 0);
}

TEST(ExampleOfStandartUsageTest5, BasicAssertions) {
  // arrange
  int rowOfChocolate = 8;
  int columnOfChocolate = 3;

  // act
  int result = chopTheChocolate(rowOfChocolate, columnOfChocolate);

  // assert
  EXPECT_EQ(result, 9);
  }