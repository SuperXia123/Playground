# pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  static std::vector<int> twoSum(std::vector<int> &nums, int target) {
    // 建表
    std::unordered_map<int, std::vector<int>> dict{};
    for (size_t i = 0; i < nums.size(); i++) {
      const auto &num = nums[i];
      dict[num].emplace_back(i);
    }

    for (const auto &term : dict) {
      // 计算目标余数
      const auto &num1 = term.first;
      int tar_num2 = target - num1;
      if (dict.find(tar_num2) == dict.end()) { continue; }
      const auto &tar_indexes = dict[tar_num2];
      // 目标余数需求数量
      if (num1 == tar_num2) {
        if (tar_indexes.size() == 2) {
          return tar_indexes;
        }
      } else {
        return {static_cast<int>(term.second.front()),
                static_cast<int>(tar_indexes.front())};
      }
    }
    return {};
  }
};

