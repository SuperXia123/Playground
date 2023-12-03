#pragma once

#include <algorithm>
#include <map>
#include <vector>

/**差分数组加速索引*/
class Solution {
public:
  int maxAliveYear(const std::vector<int> &birth,
                   const std::vector<int> &death) {
    std::vector<int> change_status(2005, 0);

    const int people_number = birth.size();
    for (int person_idx = 0; person_idx < people_number; person_idx++) {
      const int birth_year = birth[person_idx];
      const int death_year = death[person_idx];

      change_status[birth_year]++;
      change_status[death_year + 1]--;
    }

    int people_of_year{0};
    int max_people_year = -1;
    int max_people = -1;
    for (int year = 1900; year < 2001; year++) {
      people_of_year += change_status[year];
      if (people_of_year > max_people) {
        max_people = people_of_year;
        max_people_year = year;
      }
    }
    return max_people_year;
  }
};
