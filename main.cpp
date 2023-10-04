#include <vector>
#include <iostream>
#include <algorithm>

#include "solutions/程序员面试金典/面试题01.06.字符串压缩.h"

using namespace std;


int main() {
  std::string str{"abbccd"};
  auto ret = Solution().compressString(str);
  std::cout << ret << std::endl;
}
