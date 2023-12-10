#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题02.01.移除重复节点.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution{};
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(3);
  ListNode n5(2);
  ListNode n6(1);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;

  solution.removeDuplicateNodes(&n1);

  // PrintMatrix();
}
