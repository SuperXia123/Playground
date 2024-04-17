#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题10.03.搜索旋转数组.h"
#include "utils.h"

using namespace std;

int main() {
  // std::vector<int> test_input{21, 21, -21, -20, -17, -8, -6, -2, -2, -1, 0,  2,  3,  4,  4,   6,   11,  13, 14, 16, 17, 18, 20};
  //                          0   1    2    3    4   5    6   7   8   9  10  11  12  13  14   15   16   17  18  19  20  21  22  
  // std::vector<int> test_input{1, 1, 1, 1, 1, 2, 1, 1, 1};
  std::vector<int> test_input{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

  Solution solution;
  auto ret = solution.search(test_input, 5);
  PrintValue(ret);
}
