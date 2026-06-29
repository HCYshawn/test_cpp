#include "mymath/math.h"

#include <gtest/gtest.h>

TEST(AddTest, PositiveNumbers)
{
    EXPECT_EQ(mymath::add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers)
{
    EXPECT_EQ(mymath::add(-2, -3), -5);
}

TEST(AddTest, WithZero)
{
    EXPECT_EQ(mymath::add(0, 5), 5);
}

TEST(AddTest, LargeNumbers)
{
    EXPECT_EQ(mymath::add(1000000, 2000000), 3000000);
}

TEST(SubTest, PositiveNumbers)
{
    EXPECT_EQ(mymath::sub(7, 3), 4);
}

TEST(SubTest, NegativeResult)
{
    EXPECT_EQ(mymath::sub(3, 7), -4);
}

class MathFixture : public ::testing::Test
{
protected:
    int a = 10;
    int b = 4;
};

TEST_F(MathFixture, AddUsingFixture)
{
    EXPECT_EQ(mymath::add(a, b), 14);
}

TEST_F(MathFixture, SubUsingFixture)
{
    EXPECT_EQ(mymath::sub(a, b), 6);
}