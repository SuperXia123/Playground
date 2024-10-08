#pragma once

#include <iostream>
#include <vector>

template <typename T> void PrintVector(const std::vector<T> &vct) {
  std::cout << "[";
  for (const auto &x : vct) {
    std::cout << x << ", ";
  }
  std::cout << "]" << '\n';
};

template <typename T> void PrintValue(const T &val) {
  std::cout << val << std::endl;
};

template <typename T>
void PrintMatrix(const std::vector<std::vector<T>> &matrix) {
  std::cout << "[";
  for (const auto &vct : matrix) {
    PrintVector<T>(vct);
  }
  std::cout << "]" << '\n';
};

struct ListNode {
  int val;
  ListNode *next{};
  ListNode(int x) : val(x) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

inline void PrintListNode(ListNode *node) {
  while (node != nullptr) {
    std::cout << node->val << ", ";
    node = node->next;
  }
  std::cout << "\n";
}
