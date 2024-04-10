#pragma once

#include <vector>

class Solution {
public:
  std::vector<int> swapNumbers(const std::vector<int> &nums) {
    auto ret = nums;

    auto &a = ret[0];
    auto &b = ret[1];

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return ret;
  }
};
