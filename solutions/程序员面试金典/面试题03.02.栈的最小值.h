#pragma once

#include <vector>

class MinStack {
public:
  MinStack() {}

  void push(int x) {
    store_.push_back(x);

    int min;
    if (min_.empty()) {
      min = x;
    } else {
      min = x < min_.back() ? x : min_.back();
    }
    min_.push_back(min);
  }

  void pop() {
    if (store_.empty()) {
      return;
    }
    store_.erase(store_.end() - 1);
    min_.erase(min_.end() - 1);
  }

  int top() {
    if (store_.empty()) {
      return -1;
    }
    return store_.back();
  }

  int getMin() {
    if (min_.empty()) {
      return -1;
    }
    return min_.back();
  }

private:
  std::vector<int> store_{};
  std::vector<int> min_{};
};
