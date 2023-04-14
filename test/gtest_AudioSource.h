//
// Created by 23194 on 2023/3/29.
//
//#include <iostream>
//#include "gtest/gtest.h"
//using namespace std;

//double cube(double a) {return a*a*a;}
//int abs(int x) {return x>0 ? x : -x;}
//
//TEST(cube, positive)
//{ EXPECT_EQ(64,cube(4)); }
//
//TEST(IsAbsTest,JudgeTrueOrFalse)
//{
//    ASSERT_TRUE(abs(2)==2) <<"abs(2)=2";
//    ASSERT_TRUE(abs(-5)==5) <<"abs(-5)=5";
//    ASSERT_FALSE(abs(-3)==-3) <<"abs(-3)!=-3";
//    EXPECT_EQ(abs(-3),abs(3));
//    EXPECT_NE(abs(0),1);
//    ASSERT_GT(abs(-5),0);
//    ASSERT_LT(abs(4),6);
//    ASSERT_LE(-2,abs(-3));
//    ASSERT_GE(abs(-1),0);
//}
#include "gtest/gtest.h"
#include "WS2812B.h"

class WS2812BTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // 在此处创建WS2812B对象
        ws2812b = new WS2812B();
        ws2812b->begin();
    }

    virtual void TearDown() {
        // 在此处销毁WS2812B对象
        ws2812b->off();
        delete ws2812b;
    }

    // WS2812B对象
    WS2812B *ws2812b;
};

TEST_F(WS2812BTest, MatrixBottomTest) {
// 测试 matrix_bottom() 函数是否正确设置所有LED的颜色

ws2812b->matrix_bottom();

// 检查所有LED的颜色是否与dotcolors数组中的颜色之一匹配
for (int i = 0; i < LED_COUNT; i++) {
bool found = false;
for (int j = 0; j < sizeof(dotcolors) / sizeof(dotcolors[0]); j++) {
if (ws2812b->matrix[i] == dotcolors[j]) {
found = true;
break;
}
}
EXPECT_TRUE(found);
}
}



int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}