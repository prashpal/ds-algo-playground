#include <gtest/gtest.h>
#include "array.h"

// 217. Contains Duplicate
TEST(hasDuplicate, Yes) {
    Array<int> nums({1, 2, 3, 3});
    EXPECT_TRUE(nums.hasDuplicate());
}
TEST(hasDuplicate, No) {
    Array<int> nums({1, 2, 3, 4});
    EXPECT_FALSE(nums.hasDuplicate());
}

// 15. 3Sum (Solution times out on Leetcode. Investigate later.)
TEST(ThreeSum, Yes) {
    Array<int> nums({-1,0,1,2,-1,-4});
    std::vector<std::vector<int>> result;
    result = nums.threeSum();
    for(auto& item: result) {
        std::sort(item.begin(), item.end());
    }
    EXPECT_EQ(2, result.size());
    std::vector<int> vec1 = {-1, -1, 2};
    std::vector<int> vec2 = {-1, 0, 1};
    EXPECT_EQ(vec1, result[0]);
    EXPECT_EQ(vec2, result[1]);
}