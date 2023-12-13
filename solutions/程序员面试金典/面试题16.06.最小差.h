#pragma once

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

class Solution {
  struct SourcedValue {
    int val;
    bool src; // src=false means from a, else from b

    SourcedValue(int val_in, bool src_in) {
      val = val_in;
      src = src_in;
    };

    bool operator <(const SourcedValue &other) const {
      return this->val < other.val;
    };

  };

public:
  int smallestDifference(const std::vector<int> &a, const std::vector<int> &b) {
    // construct a combined vector
    std::vector<SourcedValue> vct;
    vct.reserve(a.size() + b.size());
    for (int i : a) {
      vct.emplace_back(i, false);
    }
    for (int i : b) {
      vct.emplace_back(i, true);
    }
    // sort
    std::sort(vct.begin(), vct.end());
    // find
    long min_dist = std::numeric_limits<long>::max();

    for (size_t i = 0; i + 1 < vct.size(); i++) {
      const auto &curr = vct[i];
      const auto &next = vct[i + 1];

      if (curr.src == next.src) {
        continue;
      }

      long dist = static_cast<long>(curr.val) - static_cast<long>(next.val);

      long abs_dist = std::abs(dist);
      min_dist = std::min<long>(abs_dist, min_dist);
    }

    return static_cast<int>(min_dist);
  }
};
