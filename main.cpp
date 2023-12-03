#include <vector>
#include <iostream>
#include <algorithm>

#include "utils.h"
#include "solutions/程序员面试金典/面试题16.24.数对和.h"

using namespace std;



int main() {
  Solution solution{};

  std::vector<int> nums{2, 1, 8, 6, 5, 7, -1, 3, 5, 5};

  auto ret = solution.pairSums(nums, 7);
  for (const auto &x : ret) {
    PrintVector(x);
  }
}
