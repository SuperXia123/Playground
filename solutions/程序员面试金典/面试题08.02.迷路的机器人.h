#pragma once

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  pathWithObstacles(std::vector<std::vector<int>> &obstacle_grid) {
    obstacle_grid_ptr_ = &obstacle_grid;
    columns_ = obstacle_grid.front().size();
    rows_ = obstacle_grid.size();
    visited_ = std::vector<std::vector<bool>>(
        rows_, std::vector<bool>(columns_, false));

    const std::vector<int> start{0, 0};
    if (!QueryGrid(start)) {
      return {};
    }
    return ExpandPath({start});
  }

private:
  const std::vector<std::vector<int>> *obstacle_grid_ptr_{};

  int columns_{};
  int rows_{};

  std::vector<std::vector<bool>> visited_{};

  const std::vector<std::vector<int>>
  ExpandPath(const std::vector<std::vector<int>> &path) {
    const auto &last_step = path.back();
    visited_[last_step[0]][last_step[1]] = true;

    if (last_step[0] + 1 == rows_ && last_step[1] + 1 == columns_) {
      return path;
    }

    // expand to right
    std::vector<int> right{last_step[0], last_step[1] + 1};
    if (right[1] < columns_ && QueryGrid(right)) {
      auto new_path = path;
      new_path.push_back(right);

      auto ret = ExpandPath(new_path);
      if (!ret.empty()) {
        return ret;
      }
    }

    // expand to down
    std::vector<int> down{last_step[0] + 1, last_step[1]};
    if (down[0] < rows_ && QueryGrid(down)) {
      auto new_path = path;

      new_path.push_back(down);
      auto ret = ExpandPath(new_path);
      if (!ret.empty()) {
        return ret;
      }
    }

    return {};
  }

  bool QueryGrid(const std::vector<int> &grid) const {
    return obstacle_grid_ptr_->at(grid.at(0)).at(grid.at(1)) == 0 &&
           !visited_.at(grid.at(0)).at(grid.at(1));
  }
};
