#pragma once

#include <iostream>
#include <string>

class Solution {
public:
  bool isFlipedString(const std::string &str1, const std::string &str2) {
    if (str1.size() != str2.size()) {
      return false;
    }
    if (str1 == str2) {
      return true;
    }

    for (int i = 1; i < str1.size(); i++) {
      auto flipped = FlipString(str1, i);
      if (flipped == str2) {
        return true;
      }
    }

    return false;
  }

  bool isFlippedStringSolutionV2(
    const std::string &str1, const std::string &str2) {
    return (str1.size() == str2.size()) &&
           ((str1 + str1).find(str2) != std::string::npos);
  }

private:
  static std::string FlipString(const std::string &str, int st) {
    std::string flipped = str.substr(st, str.size() - 1);
    flipped += str.substr(0, st);
    return flipped;
  }
};

