#pragma once

#include <algorithm>
#include <iterator>
#include <set>
#include <vector>

#include "../../utils.h"

class Solution {
public:
  std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }

    std::set<int> sorted_nums(nums.begin(), nums.end());
    std::vector<std::vector<int>> all_subsets{{}};

    int last_batch_idx_mark = 0;
    std::vector<std::vector<int>> batch_subsets{};
    batch_subsets.reserve(nums.size());
    for (int subset_size = 1; subset_size <= nums.size(); subset_size++) {

      for (int idx = last_batch_idx_mark; idx < all_subsets.size(); idx++) {
        const auto &ref = all_subsets[idx];

        auto start_iter = sorted_nums.begin();
        if (!ref.empty()) {
          start_iter = std::upper_bound(sorted_nums.begin(), sorted_nums.end(),
                                        ref.back());
        }
        for (auto iter = start_iter; iter != sorted_nums.end(); ++iter) {
          auto new_set{ref};
          new_set.push_back(*iter);
          batch_subsets.push_back(new_set);
        }
      }

      last_batch_idx_mark = all_subsets.size();
      all_subsets.insert(all_subsets.end(),
                         std::make_move_iterator(batch_subsets.begin()),
                         std::make_move_iterator(batch_subsets.end()));
      batch_subsets.clear();
    }
    return all_subsets;
  }
};
