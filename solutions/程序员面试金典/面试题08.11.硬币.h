#pragma once

#include <array>
#include <vector>

class Solution {
public:
  int waysToChange(int n) {
    const std::array<int, 4> coins{1, 5, 10, 25};
    constexpr int kMod = 1000000007;

    if (n == 0) {
      return 0;
    }

    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (const auto &coin : coins) {
      for (int i = coin; i <= n; i++) {
        dp[i] = (dp[i] + dp[i - coin]) % kMod;
      }
    }

    return dp[n];
  }
};
