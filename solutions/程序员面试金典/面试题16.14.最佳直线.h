#pragma once

#include <cstddef>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
  struct Line {
  public:
    Line(const std::vector<int> &pt1, const std::vector<int> &pt2)
        : k_(0.0), b_(0.0), is_vertical_(false), x_(0) {
      double x1 = pt1[0];
      double y1 = pt1[1];
      double x2 = pt2[0];
      double y2 = pt2[1];

      if (x1 == x2) {
        is_vertical_ = true;
        x_ = x1;
        return;
      }

      k_ = (y1 - y2) / (x1 - x2);
      b_ = y1 - k_ * x1;
    }

    bool operator==(const Line &other) const {
      return (k_ == other.k_) && (b_ == other.b_) &&
             (is_vertical_ == other.is_vertical_) && (x_ == other.x_);
    }

    void Init() {}

  public:
    double k_;
    double b_;
    bool is_vertical_;
    int x_;
  };

  struct LineHash {
    auto operator()(const Line &line) const {
      return (std::hash<double>()(line.k_) << 1) ^
             (std::hash<double>()(line.b_));
    }
  };

public:
  std::vector<int> bestLine(const std::vector<std::vector<int>> &points) {
    std::unordered_map<Line, std::set<int>, LineHash> line_index_mapping;

    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        const Line line(points[i], points[j]);

        auto &idx_set = line_index_mapping[line];
        idx_set.insert(i);
        idx_set.insert(j);
      }
    }

    auto best = std::max_element(
        line_index_mapping.begin(), line_index_mapping.end(),
        [](const auto &term1, const auto &term2) {
          if (term1.second.size() == term2.second.size()) {
            if (*term1.second.begin() == *term2.second.begin()) {
              return *++term1.second.begin() > *++term2.second.begin();
            }
            return *term1.second.begin() > *term2.second.begin();
          }
          return term1.second.size() < term2.second.size();
        });

    return {best->second.begin(), ++ ++best->second.begin()};
  }
};
