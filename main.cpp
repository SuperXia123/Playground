#include <vector>
#include <iostream>
#include <algorithm>

#include "solutions/程序员面试金典/面试题01.09.字符串轮转.h"

using namespace std;


int main() {
  auto ret = Solution().isFlipedString("a", "a");

  std::cout << "ret is " << ret << std::endl;
}
