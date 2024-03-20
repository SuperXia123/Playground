#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题02.02.返回倒数第k个节点.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;
  std::vector<int> test_input{10, 9, 2, 5, 3, 7, 101, 18};
  ListNode node1(10);
  ListNode node2(8);
  ListNode node3(4);
  ListNode node4(3);
  ListNode node5(7);
  
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  auto ret = solution.kthToLast(&node1, 3);
  PrintValue(ret);
}
