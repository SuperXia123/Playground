//
// Created by xia on 23-9-16.
//

#pragma once

#include <vector>
#include <algorithm>

class Solution {
 public:
  static int findContentChildren(std::vector<int> &children,
                                 std::vector<int> &biscuits) {
    // 排序
    std::sort(children.begin(), children.end());
    std::sort(biscuits.begin(), biscuits.end());
    // 逆序遍历饼干，每个尽可能给胃口最大的小孩
    int match_num{0};
    int child_idx = static_cast<int>(children.size() - 1);
    for (auto iter = biscuits.rbegin(); iter != biscuits.rend();) {
      const auto &biscuit = *iter;
      const auto &child = children[child_idx];
      // 不满足小孩胃口，后续的饼干都不可能满足
      if (biscuit < child) {
        child_idx--;
      } else {
        iter++;
        child_idx--;
        match_num++;
      }
      if (child_idx < 0) { break; }
    }
    return match_num;
  }
};
