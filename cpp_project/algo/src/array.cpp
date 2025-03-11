#include "array.h"
#include <set>

bool hasDuplicate(std::vector<int>& nums) {
    std::set<int> unique_nums = {};
    for(const auto& num: nums) {
        if (unique_nums.find(num) != unique_nums.end()) return true;
        else unique_nums.insert(num);
    }
    return false;
}