#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int respace(const std::vector<std::string> &dictionary,
              const std::string &sentence) {
    if (sentence.empty()) {
      return 0;
    }
    // mapping for dictionary
    std::unordered_set<std::string> dict_set(dictionary.begin(),
                                             dictionary.end());

    std::vector<std::vector<int>> index_unknown_dp(
        sentence.size(), std::vector<int>(sentence.size() + 1, -1));
    for (int i = 0; i < sentence.size(); i++) {
      for (int j = i + 1; j <= sentence.size(); j++) {
        const auto &sub_str = sentence.substr(i, j - i);
        if (dict_set.find(sub_str) != dict_set.end()) {
          index_unknown_dp[i][j] = 0;
        } else {
          index_unknown_dp[i][j] = j - i;
        }
      }
    }

    for (int i = 1; i <= sentence.size(); i++) {

      int min_miss = index_unknown_dp[0][i];
      for (int j = 1; j < i; j++) {
        int left = index_unknown_dp[0][j];
        int right = index_unknown_dp[j][i];
        // if (i == 10) {
        //   std::cout << "[debug] left=" << sentence.substr(0, j) << " hits "
        //             << left << ", right of " << sentence.substr(j, i - j)
        //             << " hits " << right << std::endl;
        // }
        min_miss = std::min(min_miss, left + right);
      }

      index_unknown_dp[0][i] = min_miss;
      // std::cout << "[debug] (0, " << i << ") of " << sentence.substr(0, i)
      //           << " missed " << min_miss << " words" << std::endl;
    }

    return index_unknown_dp[0][sentence.size()];
  }
};
