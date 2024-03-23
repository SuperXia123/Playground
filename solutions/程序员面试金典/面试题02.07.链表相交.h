#pragma once

#include "../../utils.h"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }

    ListNode *ptr1(headA);
    ListNode *ptr2(headB);

    bool is_a_guided{false};
    bool is_b_guided{false};

    while (true) {
      if (ptr1 == nullptr && !is_a_guided) {
        ptr1 = headB;
        is_a_guided = true;
      }
      if (ptr2 == nullptr && !is_b_guided) {
        ptr2 = headA;
        is_b_guided = true;
      }

      if (ptr1 == ptr2) {
        return ptr1;
      }

      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
  }
};
