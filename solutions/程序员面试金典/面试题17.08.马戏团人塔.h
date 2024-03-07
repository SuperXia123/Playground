#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  int bestSeqAtIndex(const std::vector<int> &height,
                     const std::vector<int> &weight) {
    const int n = height.size();

    // initialize index vector
    std::vector<int> index_vct(n);
    std::iota(index_vct.begin(), index_vct.end(), 0);

    // sorting
    std::sort(index_vct.begin(), index_vct.end(), [&](int idx1, int idx2) {
      if (height[idx1] != height[idx2]) {
        return height[idx1] < height[idx2];
      }
      return weight[idx1] > weight[idx2];
    });

    // converting to longest increasing sub-sequence problem
    std::vector<int> tar_vct;
    tar_vct.reserve(n);
    for (const auto &idx : index_vct) {
      tar_vct.push_back(weight[idx]);
    }

    std::vector<int> smallest_end{};
    for (const auto &num : tar_vct) {
      auto iter =
          std::lower_bound(smallest_end.begin(), smallest_end.end(), num);
      if (iter == smallest_end.end()) {
        smallest_end.push_back(num);
      } else {
        *iter = num;
      }
    }
    return smallest_end.size();
  }
};
