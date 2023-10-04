#pragma once

#include <set>
#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    std::set<int> cols{};
    std::set<int> rows{};

    // 计算所有需要变0的行和列
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.front().size(); j++) {
        if (matrix[i][j] != 0) {
          continue;
        }
        rows.insert(i);
        cols.insert(j);
      }
    }
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.front().size(); j++) {
        if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
          continue;
        }
        matrix[i][j] = 0;
      }
    }
  }
};
