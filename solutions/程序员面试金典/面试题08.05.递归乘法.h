#pragma once

class Solution {
public:
  int multiply(int A, int B) {
    if (A == 0 || B == 0) {
      return 0;
    }
    return multiplyOnce(A, B);
  }

private:
  int multiplyOnce(int a, int b) {
    if (a == 1) {
      return b;
    }
    if (b == 1) {
      return a;
    }

    bool is_a_smaller = a < b;
    if (is_a_smaller) {
      return b + multiplyOnce(a - 1, b);
    } else {
      return a + multiplyOnce(b - 1, a);
    }
  }
};
