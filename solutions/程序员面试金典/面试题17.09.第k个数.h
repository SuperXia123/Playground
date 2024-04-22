#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

#include "../../utils.h"

using namespace std;

class Solution {
  const std::array<int, 3> roots{3, 5, 7};

public:
  int getKthMagicNumber(int k) {
    std::vector<int> dp{1};

    std::vector<int> pointers(3, 0);
    while (dp.size() < k) {

      std::vector<int> pointer_indices{};
      int min_infered{-1};
      for (int i = 0; i < pointers.size(); i++) {
        int ptr = pointers.at(i);
        int pointed_val = dp[ptr];
        int infered = pointed_val * roots.at(i);

        if (min_infered == -1 || infered < min_infered) {
          pointer_indices.clear();
          pointer_indices.push_back(i);
          min_infered = infered;
        } else if (infered == min_infered) {
          pointer_indices.push_back(i);
        }
      }

      dp.push_back(min_infered);
      for (const auto pointer_idx : pointer_indices) {
        pointers[pointer_idx]++;
      }
    }

    return dp.back();
  }
};
