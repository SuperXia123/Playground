#pragma once

#include <vector>

#include "../../utils.h"

class Solution {
public:
  std::vector<int> findSquare(const std::vector<std::vector<int>> &matrix) {
    const int matrix_size = matrix.size();

    // construct two querying dictionaries
    std::vector<std::vector<int>> down_dict(matrix_size,
                                            std::vector<int>(matrix_size, 0));
    std::vector<std::vector<int>> right_dict(matrix_size,
                                             std::vector<int>(matrix_size, 0));

    for (int row = matrix_size - 1; row >= 0; row--) {
      for (int col = matrix_size - 1; col >= 0; col--) {
        int down_black_num =
            (row == matrix_size - 1) ? 0 : down_dict[row + 1][col];
        int right_black_num =
            (col == matrix_size - 1) ? 0 : right_dict[row][col + 1];
        if (matrix[row][col] == 0) {
          down_black_num++;
          right_black_num++;
        } else {
          down_black_num = 0;
          right_black_num = 0;
        }
        down_dict[row][col] = down_black_num;
        right_dict[row][col] = right_black_num;
      }
    }

    // PrintMatrix(right_dict);
    // PrintMatrix(down_dict);

    for (int sub_matrix_size = matrix_size; sub_matrix_size > 0;
         sub_matrix_size--) {

      for (int up = 0; up + sub_matrix_size <= matrix_size; up++) {
        for (int left = 0; left + sub_matrix_size <= matrix_size; left++) {
          int right = left + sub_matrix_size - 1;
          int down = up + sub_matrix_size - 1;

          // check upper edge
          if (right_dict[up][left] < sub_matrix_size) {
            continue;
          }
          // check lower edge
          if (right_dict[down][left] < sub_matrix_size) {
            continue;
          }
          // check left edge
          if (down_dict[up][left] < sub_matrix_size) {
            continue;
          }
          // check right edge
          if (down_dict[up][right] < sub_matrix_size) {
            continue;
          }

          return {up, left, sub_matrix_size};
        }
      }
    }

    return {};
  }
};
