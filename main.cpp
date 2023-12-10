#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题01.07.旋转矩阵.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};
std::vector<std::vector<int>> matrix {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16},
  };

  solution.rotate(matrix);

  PrintMatrix(matrix);
}
