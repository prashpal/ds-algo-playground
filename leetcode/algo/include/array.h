#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

template <typename T>
class Array {
public:
    explicit Array(std::vector<T> input) : data(std::move(input)) {}
    ~Array() = default;

    // const reference returns a reference to avoid copying of entire data
    const std::vector<T>& getData() const{
        return data;
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

    bool hasDuplicate() const{
        std::unordered_set<T> seen;
        for(T item: data) {
            if(seen.find(item) != seen.end()) return true;
            seen.insert(item);
        }
        return false;
    }

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

private:
    std::vector<T> data;
};