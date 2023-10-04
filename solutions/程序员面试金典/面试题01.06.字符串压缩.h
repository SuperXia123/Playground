#pragma once

#include <string>

class Solution {
public:
  std::string compressString(const std::string &str) {
    if (str.empty()) { return str; }

    std::string compressed{};

    char cur_char{str.front()};
    int cur_num{};
    for (const auto &c : str) {
      if (c != cur_char) {
        // 归档上一个
        compressed += cur_char;
        compressed += std::to_string(cur_num);
        // 重置状态记录器
        cur_char = c;
        cur_num = 0;
      }
      cur_num++;
    }
    // 归档上一个
    compressed += cur_char;
    compressed += std::to_string(cur_num);

    return compressed.size() < str.size() ? compressed : str;
  }
};
