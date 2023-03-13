//
// Created by lvjin on 10/03/2023.
//
#include <iostream>
#include "gtest/gtest.h"
int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) { result *= i; }
    return result;
}

TEST(FactorialTest,Negative)
{
    EXPECT_EQ(1,Factorial(-8));
    EXPECT_EQ(1, Factorial(-10));
    EXPECT_EQ(1,Factorial(-15));
}

TEST(FactorialTest,0)
{
    EXPECT_EQ(1,Factorial(0));
}

TEST(FactorialTest,Positive)
{
    EXPECT_EQ(6,Factorial(3));
    EXPECT_EQ(Factorial(4),24);
    EXPECT_EQ(Factorial(5),120);
}