#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  bool canPermutePalindrome(const std::string &str) {
    // 统计每个字符出现的频次
    std::unordered_map<char, int> char_cnt_map{};
    for (const auto &c : str) {
      char_cnt_map[c] += 1;
    }

    int even_char_num{0};
    for (const auto &term : char_cnt_map) {
      // 偶数次的字符不影响回文特性
      if (term.second % 2 == 0) {
        continue;
      }
      if (++even_char_num > 1) {
        return false;
      }
    }
    return true;
  }
};
