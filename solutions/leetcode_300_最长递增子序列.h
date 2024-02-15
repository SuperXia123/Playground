#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  int lengthOfLIS(std::vector<int> &nums) {
    std::vector<int> dp{};

    for (const auto &num : nums) {
      auto pos = std::lower_bound(dp.begin(), dp.end(), num);
      if (pos == dp.end()) {
        dp.push_back(num);
      } else {
        *pos = num;
      }
    }

    return dp.size();
  }
};
