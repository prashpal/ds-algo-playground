#include "array.h"

// 217 - https://leetcode.com/problems/contains-duplicate/ 
bool ArrayAlgorithms::hasDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for(int item: nums) {
        if(seen.find(item) != seen.end()) return true;
        seen.insert(item);
    }
    return false;
}

// 15 - https://leetcode.com/problems/3sum/description/
std::vector<std::vector<int>> ArrayAlgorithms::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> sortedData = nums; 
    std::sort(sortedData.begin(), sortedData.end());
    std::size_t size = sortedData.size();
    if (size < 3) return {}; // Edge case: Not enough elements
    for(std::size_t i = 0; i < size; ++i) {
        // ignore duplicates for first element 
        if ((i > 0) && (sortedData[i] == sortedData[i - 1])) continue;
        std::size_t start = i + 1;
        std::size_t end = size - 1;
        while (start < end) {
            int data1 = sortedData[i];
            int data2 = sortedData[start];
            int data3 = sortedData[end];
            int threesum = data1 + data2 + data3;
            if (threesum == 0) {
                result.push_back({data1, data2, data3});
                ++start;
                --end;
                // ignore duplicates for second and third elements
                while (start < end && sortedData[start] == sortedData[start - 1]) ++start;
                while (start < end && sortedData[end] == sortedData[end + 1]) --end;
            }
            else if (threesum < 0) ++start;
            else --end;
        }
    }
    return result;
}

// 125 - https://leetcode.com/problems/valid-palindrome/description/
bool ArrayAlgorithms::isPalindrome(std::string s) {
    std::size_t size = s.length();
    if (size < 2) return true;
    std::size_t left = 0;
    std::size_t right = size - 1;
    while (left < right) {
        if (!std::isalnum(s[left])) {
            ++left;
            continue;
        }
        if (!std::isalnum(s[right])) {
            --right;
            continue;
        }
        if (std::tolower(s[left]) != std::tolower(s[right])) return false;
        ++left;
        --right;
    }
    return true;
}
