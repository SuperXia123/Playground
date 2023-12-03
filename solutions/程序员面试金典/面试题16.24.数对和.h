#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> pairSums(const std::vector<int> &nums,
                                         int target) {
    // build map
    std::unordered_map<int, int> num_freq_mapping{};
    for (const auto &num : nums) {
      num_freq_mapping[num] += 1;
    }
    
    std::vector<std::vector<int>> ret{};
    for (const auto &num : nums) {
      const int paired = target - num;

      if (num_freq_mapping[num]-- <=0 || num_freq_mapping[paired]-- <= 0) {
        continue;
      }
      ret.emplace_back(std::vector<int>{num, paired});
    }

    return ret;
  }
};
