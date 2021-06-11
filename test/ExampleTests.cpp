#include <gtest/gtest.h>

#include "Example.hpp"

/* We can use a fixture like this where we can have some common variables declation that we want to be used in multiple test */
/* This struct would inherit from the base class ::testing::Test, and we will override the SetUp and TearDown functions,
There are more API we can check inside it for other purposes  */
struct ExampleTest : public ::testing::Test {
  int* x;

  virtual void SetUp() override {
    std::cout << "Setting up .." << std::endl;
    x = new int(12);
  }

  virtual void TearDown() override {
    std::cout << "Tearing Down .." << std::endl;
    delete x;
  }

  int get_x() { return *x; }
};

TEST(ExampleTests, DemonstrateMacros) {
  /* This will pass */
  EXPECT_TRUE(true);

  /* This will fail, but continue the execution */
  //   EXPECT_TRUE(false);

  /* Passes */
  ASSERT_TRUE(true);

  /* fails and stop execution here */
  //   ASSERT_TRUE(false);

  /* passes */
  ASSERT_FALSE(false);
}

TEST(TestFactorial, factorial) {
  /* You only see the std out print like cout/printf while you actually execute the build binary for this test project file */
  std::cout << "Testing Factorial func" << std::endl;

  int res = factorial(4);
  /* When the test fails, the output will be printed, otherwise the test just passes without any prints */
  EXPECT_EQ(24, res) << "Expected : 24, got : " << res;

  res = factorial(0);
  EXPECT_EQ(0, res) << "Expected : 0, got : " << res;

  res = factorial(1);
  EXPECT_EQ(1, res) << "Expected : 1, got : " << res;
}

TEST(TestSquare, square) {
  std::cout << "Testing Square func" << std::endl;
  int res = square(5);
  EXPECT_EQ((25), res) << "Expected : 25, got : " << res;
}

/* To use the fixture, we need to write TEST_F(FixtureClassName, testname) */
TEST_F(ExampleTest, TestSquareF) {
  int exp_res = get_x() * get_x();
  EXPECT_EQ(exp_res, square(get_x()));
}

/* To use the fixture, we need to write TEST_F(FixtureClassName, testname) */
TEST_F(ExampleTest, factorialF) {
  int exp_res = 479001600;
  EXPECT_EQ(exp_res, factorial(get_x()));
}