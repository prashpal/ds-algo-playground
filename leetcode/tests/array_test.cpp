#include <gtest/gtest.h>
#include "array.h"

// 217. Contains Duplicate
TEST(array, hasduplicate) {
    Array<int> nums({1, 2, 3, 3});
    EXPECT_TRUE(nums.hasDuplicate());
    nums.setData({1, 2, 3, 4});
    EXPECT_FALSE(nums.hasDuplicate());
}

// 15. 3Sum (Solution times out on Leetcode. Investigate later.)
TEST(Array, ThreeSum) {
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

// 125. Valid Palindrome
TEST(array, ispalindrome) {
    Array<char> input;
    std::string str = "Hello, world!";
    input.setData(std::vector<char>(str.begin(), str.end()));
    EXPECT_FALSE(input.isPalindrome());
    str = "malayalam";
    std::vector<char> char_vector2(str.begin(), str.end());
    Array<char> input2(char_vector2);
    EXPECT_TRUE(input2.isPalindrome());
}