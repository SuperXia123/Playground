#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题17.09.第k个数.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  auto ret = solution.getKthMagicNumber(251);
  PrintValue(ret);
}
