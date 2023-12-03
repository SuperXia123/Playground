#include <algorithm>
#include <iostream>
#include <vector>

#include "solutions/程序员面试金典/面试题16.10.生存人数.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};

  std::vector<int> birth{1900, 1901, 1950};
  std::vector<int> death{1948, 1951, 2000};

  auto ret = solution.maxAliveYear(birth, death);

  PrintValue(ret);
}
