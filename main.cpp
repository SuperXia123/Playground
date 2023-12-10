#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.26.计算器.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};

  // std::string str{" - 1 "};
  // auto a1 = std::strtol(str.c_str(), nullptr, 10);
  // auto a2 = std::stoi(str);
  //
  // std::cout << "a1 is " << a1 << ", a2 is " << a2 << "\n";

  auto ret = solution.calculate("42");

  PrintValue(ret);
}
