#pragma once

#include "../../utils.h"

class Solution {
public:
  void isPalindrome(ListNode *head) {
    // calculate length
    int len{0};
    ListNode *ptr{head};
    while (ptr != nullptr) {
      len++;
      ptr = ptr->next;
    }
    ListNode *last = ptr;
    last->next = head;

    // determine

  }
};

