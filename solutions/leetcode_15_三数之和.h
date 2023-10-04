//
// Created by xia on 23-9-16.
//

#pragma once

#include <map>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret_combinations{};
    // 每个数字频次建表
    std::sort(nums.begin(), nums.end());
    std::map<int, int> num_dict{};
    for (const auto &num : nums) {
      num_dict[num] += 1;
    }
    // 两轮遍历
    for (auto iter1 = num_dict.begin(); iter1 != num_dict.end(); ++iter1) {
      // 考虑数量约束，是否允许重复
      auto iter2 = iter1;
      if (iter1->second < 2) { iter2++; }

      for (; iter2 != num_dict.end(); ++iter2) {
        // 求目标数字
        int sum = iter1->first + iter2->first;
        int tar_num = -sum;
        // 求目标数字的最小数目
        int tar_cnt = 1;
        tar_cnt += (iter1->first == tar_num);
        tar_cnt += (iter2->first == tar_num);
        // 查询是否满足条件
        auto tar_iter = num_dict.find(tar_num);
        if (tar_iter != num_dict.end() &&
            num_dict[tar_num] >= tar_cnt) {
          if (tar_num >= iter2->first) {
            ret_combinations.emplace_back(std::vector<int>{iter1->first, iter2->first, tar_num});
          }
        }
      }
    }

    return ret_combinations;
  }
};
