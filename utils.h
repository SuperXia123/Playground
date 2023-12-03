#pragma once

#include <iostream>
#include <vector>

template<typename T>
void PrintVector(const std::vector<T> &vct) {
  std::cout << "[";
  for (const auto &x : vct) {
    std::cout << x << ", ";
  }
  std::cout << "]" << std::endl;
};

template<typename T>
void PrintValue(const T &val) {
  std::cout << val << std::endl;
};
