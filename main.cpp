#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.14.最佳直线.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  std::vector<std::vector<int>> test_input{
      {0, 0},
      {1, 1},
      {1, 0},
      {2, 0},
      {2, 2},
  };

  auto ret = solution.bestLine(test_input);
  PrintVector(ret);
}
