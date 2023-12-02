#pragma once

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Solution {
  using Grid = std::pair<int, int>;

  struct AntPosition {
    int x;
    int y;
    char h; // 'L', 'U', 'R', 'D'

    void Move() {
      switch (h) {
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      default:
        exit(0);
      }
    }

    void TurnClockwise() {
      switch (h) {
      case 'L':
        h = 'U';
        break;
      case 'R':
        h = 'D';
        break;
      case 'U':
        h = 'R';
        break;
      case 'D':
        h = 'L';
        break;
      default:
        exit(1);
      }
    }

    void TurnAntiClockwise() {
      switch (h) {
      case 'L':
        h = 'D';
        break;
      case 'R':
        h = 'U';
        break;
      case 'U':
        h = 'L';
        break;
      case 'D':
        h = 'R';
        break;
      default:
        exit(2);
      }
    }
  };

public:
  std::vector<std::string> printKMoves(int K) {
    if (K == 0) {
      return {"R"};
    }
    // init
    pos_.x = 0;
    pos_.y = 0;
    pos_.h = 'R';
    chess_[Grid(0, 0)] = true;

    for (int i = 0; i < K; i++) {
      MoveOneStep();
    }

    return PrintStatus();
  }

private:
  void MoveOneStep() {
    const Grid ant_grid{pos_.x, pos_.y};
    bool is_white = chess_[ant_grid];

    if (is_white) {
      // 如果在白色格子上
      pos_.TurnClockwise();
      pos_.Move();
    } else {
      // 如果在黑色格子上
      pos_.TurnAntiClockwise();
      pos_.Move();
    }
    // 翻转颜色
    chess_[ant_grid] = !is_white;
    // 新格子加入记录
    if (chess_.find(Grid(pos_.x, pos_.y)) == chess_.end()) {
      chess_[Grid(pos_.x, pos_.y)] = true;
    }
  }

  std::vector<std::string> PrintStatus() {
    // 确定边界
    int min_x{std::numeric_limits<int>::max()};
    int min_y{std::numeric_limits<int>::max()};
    int max_x{std::numeric_limits<int>::min()};
    int max_y{std::numeric_limits<int>::min()};
    for (const auto &grid : chess_) {
      min_x = std::min(grid.first.first, min_x);
      min_y = std::min(grid.first.second, min_y);
      max_x = std::max(grid.first.first, max_x);
      max_y = std::max(grid.first.second, max_y);
    }
    int rows = max_y - min_y + 1;
    int cols = max_x - min_x + 1;
    // 初始化地图
    std::vector<std::string> paint(rows, std::string(cols, '_'));
    // 画黑色格子
    for (const auto &grid : chess_) {
      bool is_white = grid.second;
      int row = rows - 1 - (grid.first.second - min_y);
      int col = grid.first.first - min_x;
      paint[row][col] = is_white ? '_' : 'X';
    }
    // 画蚂蚁
    int row = rows - 1 - (pos_.y - min_y);
    int col = pos_.x - min_x;
    paint[row][col] = pos_.h;

    // 打印
    // std::cout << std::endl;
    // std::cout << "===============================" << std::endl;
    // for (const auto &str : paint) {
    //   std::cout << str.c_str() << std::endl;
    // }
    // std::cout << "11111111111111111111111111111111" << std::endl;

    return paint;
  }

private:
  AntPosition pos_;
  std::map<Grid, bool> chess_; // 存放黑格子位置
};
