#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题08.04.PowerSet.h"
#include "utils.h"

using namespace std;

int main() {
  std::vector<int> test_input{1, 2, 3};

  Solution solution;
  auto ret = solution.subsets(test_input);
  for (const auto &grid : ret) {
    PrintVector(grid);
  }
}
