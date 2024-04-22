#pragma once

#include <cstdint>
#include <string>
#include <unordered_set>

class Solution {
public:
  bool isUnique(const std::string &str) {
    int32_t dict{0};

    for (const auto &c : str) {
      int idx = c - 'a';
      int32_t mask = 1 << idx;

      if ((dict & mask) != 0) {
        return false;
      }

      dict |= mask;
    }
    return true;
  }
};

