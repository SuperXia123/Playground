#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/solution_devide.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;
  auto ret = solution.Divide(5, 3);
  std::cout << "ret is " << ret << '\n';
}
