#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class WordsFrequency {
public:
  WordsFrequency(const std::vector<std::string> &book) {
    for (const auto &word : book) {
      word_freq_mapping_[word]++;
    }
  }

  int get(const std::string &word) {
    if (word_freq_mapping_.find(word) == word_freq_mapping_.end()) {
      return 0;
    }
    return word_freq_mapping_[word];
  }

private:
  std::unordered_map<std::string, int> word_freq_mapping_{};
};
