#pragma once

#include <vector>

class Solution {
public:
  int waysToStep(int n) {
    constexpr int kMod = 1000000007; 

    std::vector<int> dp{1, 1, 2};
    if (n < 3) {
      return dp[n];
    }

    for (int i = 3; i <= n; i++) {
      int ret = ((dp[0] + dp[1]) % kMod + dp[2]) % kMod;
      dp[0] = dp[1];
      dp[1] = dp[2];
      dp[2] = ret;
    }

    return dp[2];
  }
};
