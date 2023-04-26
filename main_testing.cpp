#include <iostream>
#include "functions.h"
#include "gtest/gtest.h"
#include <cmath>

TEST(test_func, radius){
    Curve limacon(0.5, 1.5);
    ASSERT_DOUBLE_EQ(1.5 + 0.5 * cos(5), limacon.radius(5));
}

TEST(test_func, get_area){
    Curve limacon(0.5, 1.5);
    ASSERT_DOUBLE_EQ((pow(1.5, 2) + (pow(0.5, 2) / 2)) * M_PI, limacon.get_area());
}

int _tmain() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}