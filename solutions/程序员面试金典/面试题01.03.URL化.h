#pragma once

#include <iostream>
#include <string>

class Solution {
public:
  std::string replaceSpaces(std::string S, int length) {
    std::string ret{};
    for (size_t i = 0; i < length; i++) {
      if (S[i] != ' ') {
        ret.push_back(S[i]);
      } else {
        ret.insert(ret.size(), "%20");
      }
    }
    return ret;
  }
};
