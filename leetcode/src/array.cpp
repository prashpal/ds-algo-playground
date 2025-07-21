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

// 704 - https://leetcode.com/problems/binary-search/description/
int ArrayAlgorithms::search(std::vector<int>& nums, int target) {
    size_t len = nums.size();
    size_t left = 0;
    size_t right = len - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else {
            if (mid == 0) return -1; // Prevent underflow
            right = mid - 1;
        }
    }
    return -1;
}

// 153 - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
// TODO: can be optimized further
bool checkMin(const std::vector<int>& nums, size_t current_index) {
    size_t len = nums.size();
    size_t right_index = 0;
    size_t left_index = 0;
    if (current_index == 0) left_index = len - 1;
    else left_index = current_index - 1;
    if (current_index == len - 1) right_index = 0;
    else right_index = current_index + 1;
    if (nums[current_index] <= nums[left_index] && nums[current_index] <= nums[right_index]) return true;
    return false;
}
int ArrayAlgorithms::findMin(std::vector<int>& nums) {
    size_t len = nums.size();
    if (len == 0) return -1;
    else if (len == 1) return nums[0];
    size_t left = 0;
    size_t right = len - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (checkMin(nums, mid)) return nums[mid];
        else if (nums[mid] > nums[right]) left = mid + 1;
        else {
            if (mid == 0) return -1; // Prevent underflow
            right = mid - 1;
        }
    }
    return -1;
}
