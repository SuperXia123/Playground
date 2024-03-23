#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题02.07.链表相交.h"
#include "utils.h"

using namespace std;

int main() {
  Solution solution;

  ListNode nodea1(1);
  ListNode nodea2(2);
  ListNode nodea3(3);
  ListNode nodea4(4);
  nodea1.next = &nodea2;
  nodea2.next = &nodea3;
  nodea3.next = &nodea4;

  ListNode nodeb1(5);
  ListNode nodeb2(6);
  ListNode nodeb3(7);
  ListNode nodeb4(8);
  nodeb1.next = &nodeb2;
  nodeb2.next = &nodeb3;
  nodeb3.next = &nodeb4;

  ListNode nodec1(9);
  ListNode nodec2(11);
  ListNode nodec3(12);
  ListNode nodec4(13);
  nodec1.next = &nodec2;
  nodec2.next = &nodec3;
  nodec3.next = &nodec4;

  nodea4.next = &nodec1;
  nodeb4.next = &nodec1;

  auto ret = solution.getIntersectionNode(&nodea1, &nodeb1);
  if (ret == nullptr) {
    std::cout << "nullptr" << std::endl;
  } else {
    std::cout << ret->val << std::endl;
  }
}
