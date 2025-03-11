#include <gtest/gtest.h>
#include "array.h"

// Test 1: Check for duplicates
TEST(ArrayTest, hasDuplicateTest) {
    std::vector<int> nums = {1, 2, 3, 3};
    EXPECT_TRUE(hasDuplicate(nums));
}