#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  // 每个点记录其个方向连接状态
  // 0 1 2
  // 3 X 4
  // 5 6 7
  struct ConnectStatus {
    std::vector<int> connects;

    ConnectStatus() : connects(8, 0){};
  };

  const std::unordered_map<int, int> kIdxToRow = {
      {0, -1}, {1, -1}, {2, -1}, {3, 0}, {4, 0}, {5, 1}, {6, 1}, {7, 1},
  };
  const std::unordered_map<int, int> kIdxToCol = {
      {0, -1}, {3, -1}, {5, -1}, {1, 0}, {6, 0}, {2, 1}, {4, 1}, {7, 1},
  };

  std::string tictactoe(const std::vector<std::string> &board) {
    const int N = board.size();

    std::vector<std::vector<ConnectStatus>> all_connects(
        N, std::vector<ConnectStatus>(N));
    bool all_occupied = true;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        const char chess = board[i][j];
        if (chess == ' ') {
          all_occupied = false;
          continue;
        }
        // 遍历每一个邻居
        for (int dir_idx = 0; dir_idx < 4; dir_idx++) {
          int delta_row = kIdxToRow.at(dir_idx);
          int delta_col = kIdxToCol.at(dir_idx);
          // 继承邻居同方向连接数
          if ((i + delta_row) >= 0 && (i + delta_row) < N &&
              (j + delta_col) >= 0 && (j + delta_col) < N &&
              board[i][j] == board[i + delta_row][j + delta_col]) {
            // 此方向有邻居且字符相同
            all_connects[i][j].connects[dir_idx] =
                all_connects[i + delta_row][j + delta_col].connects[dir_idx];
          }
          // 连接数自增, 判断游戏输赢
          // std::cout << "connect num of [" << i << ", " << j << "] in direction "
          //           << dir_idx << " is "
          //           << all_connects[i][j].connects[dir_idx] + 1 << '\n';
          if (++all_connects[i][j].connects[dir_idx] >= N) {
            return {chess};
          }
        }
      }
    }

    return all_occupied ? "Draw" : "Pending";
  }
};
