#include "../../utils.h"
#include <unordered_map>
#include <vector>

class Solution {
public:
  int kthToLast(ListNode *head, int k) {
    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 0; i < k; i++) {
      fast = fast->next;
    }

    while (fast != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    return slow->val;
  }
};
