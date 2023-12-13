#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.06.最小差.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};

  std::vector<int> a{-2147483648,1};
  std::vector<int> b{2147483647,0};

  auto ret = solution.smallestDifference(a, b);
  PrintValue(ret);
}
