#pragma once

#include <vector>

class Solution {
public:
  int search(const std::vector<int> &arr, int tar) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
      int m = (l + r) / 2;

      int l_v = arr[l];
      int r_v = arr[r];
      int m_v = arr[m];

      if (l_v == tar) {
        return l;
      }
      if (m_v == tar) {
        r = m;
        continue;
      }


      if (l_v == r_v) {
        l++;
        continue;
      }

      bool is_tar_in_left_interval{false};
      if (m_v > l_v || m_v > r_v) {
        is_tar_in_left_interval = (l_v <= tar && tar <= m_v);
      } else if (m_v < l_v || m_v < r_v) {
        is_tar_in_left_interval = !(m_v <= tar && tar <= r_v);
      }

      if (is_tar_in_left_interval) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return -1;
  }
};
