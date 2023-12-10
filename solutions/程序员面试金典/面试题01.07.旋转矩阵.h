#pragma once

#include <vector>

#include "../../utils.h"

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    // 转置
    int temp;
    for (int i = 0; i < rows; i++) {
      for (int j = i + 1; j < cols; j++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }

    // 垂直镜像
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < 0.5 * cols; j++) {
        temp = matrix[i][j];
        matrix[i][j] = matrix[i][cols - 1 - j];
        matrix[i][cols - 1 - j] = temp;
      }
    }
  }
};
