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
    int search(std::vector<int>& nums, int target); // 704 - https://leetcode.com/problems/binary-search/description/
    int findMin(std::vector<int>& nums); // 153 - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
};