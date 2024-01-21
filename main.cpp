#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题17.17.多次搜索.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  std::string big {"mississippi"};
  std::vector<std::string> smalls {"","ppi","hi","sis","i","ssippi"};

  auto ret = solution.multiSearch(big, smalls);
  for (const auto &term : ret) {
    PrintVector(term);
  }
}
