#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题08.01.三步问题.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  auto ret = solution.waysToStep(5);
  PrintValue(ret);
}
