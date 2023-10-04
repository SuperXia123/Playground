#include <vector>
#include <iostream>
#include <algorithm>

#include "solutions/程序员面试金典/面试题01.04.回文排列.h"

using namespace std;


int main() {
  std::string str{"tactcoia"};

  auto ret = Solution().canPermutatePalindrome(str);

  std::cout << ret << std::endl;
}
