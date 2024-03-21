#pragma once

#include "../../utils.h"
#include <array>
#include <vector>

class TripleInOne {
public:
  TripleInOne(int stackSize) { max_size_ = stackSize; }

  void push(int stack_idx, int value) {
    if (QueryStackSize(stack_idx) == max_size_) {
      return;
    }
    // push to stack
    int pointer = pointers_[stack_idx];
    store_.insert(store_.begin() + pointer, value);
    // update pointer
    for (int i = stack_idx; i < pointers_.size(); i++) {
      pointers_[i]++;
    }
  }

  int pop(int stack_idx) {
    if (isEmpty(stack_idx)) {
      return -1;
    }
    // erase
    int ret = store_[pointers_[stack_idx] - 1];
    store_.erase(store_.begin() + pointers_[stack_idx] - 1);
    // update pointer
    for (int i = stack_idx; i < pointers_.size(); i++) {
      pointers_[i]--;
    }
    return ret;
  }

  int peek(int stack_idx) const {
    if (isEmpty(stack_idx)) {
      return -1;
    }

    return store_.at(pointers_.at(stack_idx) - 1);
  }

  bool isEmpty(int stack_idx) const {
    return QueryStackSize(stack_idx) == 0;
  }

private:
  int QueryStackSize(int stack_idx) const {
    if (stack_idx == 0) {
      return pointers_.at(0);
    }

    return pointers_.at(stack_idx) - pointers_.at(stack_idx - 1);
  }

  std::vector<int> store_;
  std::array<int, 3> pointers_{0, 0, 0};
  int max_size_;
};
