#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
  bool CheckPermutation(const std::string &str1, const std::string &str2) {
    auto map1 = CountCharNums(str1);
    auto map2 = CountCharNums(str2);

    return map1 == map2;
  }

private:
  static std::unordered_map<char, int> CountCharNums(const std::string &str) {
    std::unordered_map<char, int> char_map{};
    for (const auto &c : str) {
      char_map[c] += 1;
    }
    return char_map;
  }
};
