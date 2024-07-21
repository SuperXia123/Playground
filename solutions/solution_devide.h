#pragma once

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::string Divide(int x, int y) {
    std::string ret{};
    ret += std::to_string(static_cast<int>(x / y));

    int tar = x % y * 10;
    if (tar == 0) {
      return ret;
    }

    ret.push_back('.');
    ret.push_back('{');

    std::unordered_set<int> targets;
    while (targets.count(tar) == 0) {
      targets.insert(tar);

      int quatient = tar / y;
      int remainder = tar % y;

      ret += std::to_string(static_cast<int>(quatient));
      tar = remainder * 10;
    }

    ret.push_back('}');
    return ret;
  }
};

