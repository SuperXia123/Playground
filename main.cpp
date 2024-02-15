#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/leetcode_300_最长递增子序列.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;
  std::vector<int> test_input{10, 9, 2, 5, 3, 7, 101, 18};
  auto ret = solution.lengthOfLIS(test_input);
  PrintValue(ret);
}
