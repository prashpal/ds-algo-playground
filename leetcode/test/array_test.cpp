#include <gtest/gtest.h>
#include "array.h"

// 217 - https://leetcode.com/problems/contains-duplicate/ 
TEST(array, hasDuplicate) {
    ArrayAlgorithms arrayAlgo;
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_FALSE(arrayAlgo.hasDuplicate(nums));
    nums = {1, 2, 3, 4, 5, 1};
    EXPECT_TRUE(arrayAlgo.hasDuplicate(nums));
}

// 15 - https://leetcode.com/problems/3sum/description/
TEST(array, threesum) {
    ArrayAlgorithms arrayAlgo;
    std::vector<int> nums({-1, 0, 1, 2, -1, -4});
    std::vector<std::vector<int>> result;
    result = arrayAlgo.threeSum(nums);
    for (auto& item : result) {
        std::sort(item.begin(), item.end());
    }
    EXPECT_EQ(2, result.size());
    std::vector<int> vec1 = {-1, -1, 2};
    std::vector<int> vec2 = {-1, 0, 1};
    EXPECT_EQ(vec1, result[0]);
    EXPECT_EQ(vec2, result[1]);
}

//125 - https://leetcode.com/problems/valid-palindrome/description/
TEST(array, ispalindrome) {
    ArrayAlgorithms arrayAlgo;
    std::string str = "Hello, world!";
    EXPECT_FALSE(arrayAlgo.isPalindrome(str));
    str = "malayalam";
    EXPECT_TRUE(arrayAlgo.isPalindrome(str));
    str = "Was it a car or a cat I saw?";
    EXPECT_TRUE(arrayAlgo.isPalindrome(str));
    str = "a.";
    EXPECT_TRUE(arrayAlgo.isPalindrome(str));
}