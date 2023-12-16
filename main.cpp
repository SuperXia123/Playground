#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.20.T9键盘.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};

  std::vector<std::string> words{"a", "b", "c", "d"};
  std::string num {"2"};

  auto ret = solution.getValidT9Words(num, words);
  PrintVector(ret);
}
