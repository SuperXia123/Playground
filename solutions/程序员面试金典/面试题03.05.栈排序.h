#pragma once

#include <iostream>
#include <stack>

class SortedStack {
public:
  SortedStack() {}

  void push(int val) {
    while (!data_.empty() && data_.top() < val) {
      exchange_.push(data_.top());
      data_.pop();
    }
    data_.push(val);

    while (!exchange_.empty()) {
      data_.push(exchange_.top());
      exchange_.pop();
    }
  }

  void pop() {
    if (data_.empty()) {
      return;
    }
    data_.pop();
  }

  int peek() {
    if (data_.empty()) {
      return -1;
    }
    return data_.top();
  }

  bool isEmpty() { return data_.empty(); }

private:
  std::stack<int> data_{};
  std::stack<int> exchange_{};
};
