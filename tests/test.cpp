#include <gtest/gtest.h>

extern "C" {
    #include "sprlib.h"
    #include "mprlib.h"  
}

TEST(SPR, TestBasics) {
    struct comments b1 = {5, 2.3, 7};
    struct comments b2 = {2, 0, 0};
    EXPECT_EQ(0, zero_rate_count_func(&b1, 1));
    EXPECT_EQ(1, zero_rate_count_func(&b2, 1));
}

TEST(MPR, TestBasics) {
    struct comments2 c1 = {5, 2.3, 7};
    struct comments2 c2 = {2, 0, 0};
    EXPECT_EQ(0, zero_rate_count_func2(&c1, 1));
    EXPECT_EQ(1, zero_rate_count_func2(&c2, 1));
}
