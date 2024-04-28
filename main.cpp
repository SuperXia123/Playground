#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题17.23.最大黑方阵.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;
  std::vector<std::vector<int>> test_input{
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };

  std::vector<std::vector<int>> test_input2{
    {1, 0, 1}, 
    {0, 0, 1}, 
    {0, 0, 1}, 
  };

  auto ret = solution.findSquare({{1}});
  PrintVector(ret);
}
