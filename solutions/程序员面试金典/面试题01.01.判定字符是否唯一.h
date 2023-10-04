#pragma once

#include <string>
#include <unordered_set>

class Solution {
public:
  bool isUnique(const std::string &str) {
    std::unordered_set<char> char_dict{};

    for (const auto &c : str) {
      char_dict.insert(c);
    }

    return char_dict.size() == str.size();
  }
};

