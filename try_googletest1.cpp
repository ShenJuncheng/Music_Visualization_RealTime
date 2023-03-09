#include <iostream>
#include "gtest/gtest.h"
int add(int a,int b) {return a+b;}
TEST(add,zero) {EXPECT_EQ(0,add(0,0)) <<"yes";}
TEST(add,positive_number) {EXPECT_EQ(3,add(1,2));}
TEST(add,negative_number) {EXPECT_EQ(-3,add(-1,-2));}
int main() {::testing::InitGoogleTest();
return RUN_ALL_TESTS();}


