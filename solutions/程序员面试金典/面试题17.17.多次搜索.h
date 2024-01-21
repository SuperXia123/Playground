#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../../utils.h"

class Solution {
public:
  std::vector<std::vector<int>> multiSearch(const std::string &big,
                                            const std::vector<std::string> &smalls) {
    // mapping index of big-characters to accelerate
    std::unordered_map<char, std::vector<int>> big_idx_mapping{};
    for (int i = 0; i < big.size(); i++) {
      big_idx_mapping[big[i]].push_back(i);
    }

    std::vector<std::vector<int>> ret(smalls.size(), std::vector<int>());
    for (int i = 0; i < smalls.size(); i++) {
      const auto &small = smalls[i];
      if (small.empty()) {
        continue;
      }
      auto &small_indices = ret[i];

      for (const auto &tar_idx : big_idx_mapping[small[0]]) {
        const auto &big_sub_str = big.substr(tar_idx, small.size());
        if (big_sub_str == small) {
          small_indices.push_back(tar_idx);
        }
      }
    }
    return ret;
  }
};
