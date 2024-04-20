#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题03.02.栈的最小值.h"
#include "utils.h"

using namespace std;

int main() {
  MinStack solution;

  solution.push(-2);
  solution.push(0);
  solution.push(-3);

  solution.getMin();
  solution.pop();
  solution.top();
  solution.getMin();
}
