#pragma once

#include <iostream>
#include <string>

class Solution {
public:
  bool oneEditAway(const std::string &first, const std::string &second) {
    bool is_first_longer = (first.size() > second.size());
    auto &longer = is_first_longer ? first : second;
    auto &shorter = is_first_longer ? second : first;

    if (longer.size() - shorter.size() > 1) {
      return false;
    }

    int forward_diff_idx = -1;
    {
      for (int i = 0; i < shorter.size(); i++) {
        if (shorter[i] != longer[i]) {
          forward_diff_idx = i;
          break;
        }
      }
      if (forward_diff_idx == -1) {
        return longer.size() - shorter.size() <= 1;
      }
    }

    int backward_diff_idx = -1;
    {
      for (int i = 0; i < shorter.size(); i++) {
        if (shorter[shorter.size() - 1 - i] != longer[longer.size() - 1 - i]) {
          backward_diff_idx = i;
          break;
        }
      }
      if (backward_diff_idx == -1) {
        return longer.size() - shorter.size() <= 1;
      }
    }

    // std::cout << "[debug] forward is " << forward_diff_idx << ", backward is
    // "
    //           << backward_diff_idx << std::endl;
    return (longer.size() - forward_diff_idx - backward_diff_idx <= 1);
  }
};
