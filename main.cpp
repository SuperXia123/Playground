#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题17.13.恢复空格.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  std::vector<std::string> dictionary {"looked","just","like","her","brother"};
  std::string sentence{""};

  auto ret = solution.respace(dictionary, sentence);
  PrintValue(ret);
}
