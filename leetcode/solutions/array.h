#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cctype>

template <typename T>
class Array {
public:
    Array() = default;
    explicit Array(std::vector<T> input) : data(std::move(input)) {}
    ~Array() = default;

    // const reference returns a reference to avoid copying of entire data
    const std::vector<T>& getData() const{
        return data;
    }

    // use rvalue reference and move semantics to avoid copying
    void setData(std::vector<T>&& newData) {
        data = std::move(newData);
    }

    std::vector<T> getSorted() const {
        std::vector<T> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        return sortedData;
    }

    void print() {
        if (data.empty()) {
            std::cout << "Array is empty";
            return;
        }
        std::size_t size = data.size();
        for(std::size_t i = 0; i < size; ++i) {
            if (i == size - 1) std::cout << data[i] << "\n";
            else std::cout << data[i] << ",";
        }
    }

    // 217. Contains Duplicate
    bool hasDuplicate() const{
        std::unordered_set<T> seen;
        for(T item: data) {
            if(seen.find(item) != seen.end()) return true;
            seen.insert(item);
        }
        return false;
    }

    // 15. 3Sum (Solution times out on Leetcode. Investigate later.)
    std::vector<std::vector<T>> threeSum() {
        std::vector<std::vector<T>> result;
        std::vector<T> sortedData = this->getSorted();
        std::size_t size = sortedData.size();
        if (size < 3) return {}; // Edge case: Not enough elements
        for(std::size_t i = 0; i < size; ++i) {
            // ignore duplicates for first element 
            if ((i > 0) && (sortedData[i] == sortedData[i - 1])) continue;
            std::size_t start = i + 1;
            std::size_t end = size - 1;
            while (start < end) {
                T data1 = sortedData[i];
                T data2 = sortedData[start];
                T data3 = sortedData[end];
                T threesum = data1 + data2 + data3;
                std::cout <<  "Result : " << threesum << "\n";
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

    // 125. Valid Palindrome
    bool isPalindrome() const {
        std::size_t size = data.size();
        if (size < 2) return true;
        std::size_t left = 0;
        std::size_t right = size - 1;
        while (left < right) {
            while (left < right && !std::isalnum(data[left])) ++left;
            while (left < right && !std::isalnum(data[right])) --right;
            if (std::tolower(data[left]) != std::tolower(data[right])) return false;
            ++left;
            --right;
        }
        return true;
    }

private:
    std::vector<T> data;
};