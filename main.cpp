#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.04.井字游戏.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};

  std::vector<std::string> board{"OOX","XXO","OXO"};

  auto ret = solution.tictactoe(board);
  PrintValue(ret);
}
