#include <unordered_set>
#include "../../utils.h"


class Solution {
public:
  ListNode *removeDuplicateNodes(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *curr = head;
    std::unordered_set<int> number_set{curr->val};
    while (curr->next != nullptr) {
      bool is_next_duplicate = (number_set.find(curr->next->val) != number_set.end());
      number_set.insert(curr->next->val);

      if (is_next_duplicate) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }

    return head;
  }
};
