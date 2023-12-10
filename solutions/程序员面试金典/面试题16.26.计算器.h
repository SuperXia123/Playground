#pragma once

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  int calculate(const std::string &s) {
    std::vector<int> stack{};

    char pre_sign = '+';
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      const auto &curr = s[i];
      const std::string aaa{curr};

      // 读到数字，更新num
      if (std::isdigit(curr) != 0) {
        num = num * 10 + std::stoi(s.substr(i, 1));
      }

      // 结算num
      if (curr != '+' && curr != '-' && curr != '*' && curr != '/' && i != s.size() - 1) {
        continue;
      }
      switch (pre_sign) {
      case '+':
        stack.push_back(num);
        break;
      case '-':
        stack.push_back(-num);
        break;
      case '*':
        stack.back() *= num;
        break;
      case '/':
        stack.back() /= num;
        break;
      default:
        exit(1);
      }
      pre_sign = curr;
      num = 0;
    }

    return std::accumulate(stack.begin(), stack.end(), 0);
  }
};
