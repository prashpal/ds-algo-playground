#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

class ArrayAlgorithms {
public:
    bool hasDuplicate(std::vector<int>& nums); // 217 - https://leetcode.com/problems/contains-duplicate/
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums); // 15 - https://leetcode.com/problems/3sum/description/
    bool isPalindrome(std::string s); // 125 - https://leetcode.com/problems/valid-palindrome/description/
};