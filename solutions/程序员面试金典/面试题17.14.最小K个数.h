#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> smallestK(std::vector<int> &arr, int k) {
    std::sort(arr.begin(), arr.end());
    return {arr.begin(), arr.begin() + k};
  }
};

