#pragma once

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    if (matrix.front().empty()) {
      return false;
    }

    const int row_num = matrix.size();
    const int col_num = matrix.front().size();

    std::pair<int, int> curr{row_num - 1, 0};
    while (curr.first >= 0 && curr.second < col_num) {
      const int curr_val = matrix[curr.first][curr.second];
      if (curr_val == target) {
        return true;
      }

      if (curr_val < target) {
        curr.second++;
        continue;
      }

      if (curr_val > target) {
        curr.first--;
        continue;
      }
    }
    return false;
  }
};
