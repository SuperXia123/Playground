#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题08.02.迷路的机器人.h"
#include "utils.h"

using namespace std;

int main() {
  std::vector<std::vector<int>> test_input {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0},
  };

  Solution solution;
  auto ret = solution.pathWithObstacles(test_input);
  for (const auto &grid : ret) {
    PrintVector(grid);
  }
}
