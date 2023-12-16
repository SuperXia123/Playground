#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution { public: std::vector<std::string>
  getValidT9Words(const std::string &num,
                  const std::vector<std::string> &words) {
    // build a digit-alpha mapping
    std::unordered_map<char, char> char_num_mapping {
      {'a', '2'}, {'b', '2'}, {'c', '2'},
      {'d', '3'}, {'e', '3'}, {'f', '3'},
      {'g', '4'}, {'h', '4'}, {'i', '4'},
      {'j', '5'}, {'k', '5'}, {'l', '5'},
      {'m', '6'}, {'n', '6'}, {'o', '6'},
      {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
      {'t', '8'}, {'u', '8'}, {'v', '8'},
      {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'},
    };

    std::unordered_map<std::string, std::string> word_num_mapping{};
    for (const auto &word : words) {
      std::string &corresponding_num_combinition = word_num_mapping[word];
      corresponding_num_combinition.reserve(word.size());

      for (const auto &letter : word) {
        char corresponding_num = char_num_mapping[letter];
        corresponding_num_combinition += corresponding_num;
      }
    }

    // revert mapping
    std::unordered_map<std::string, std::vector<std::string>> num_word_mapping{};
    for (const auto &term : word_num_mapping) {
      const auto &num = term.second;
      const auto &word = term.first;

      num_word_mapping[num].push_back(word);
    }

    std::cout << "mapping is " << std::endl;
    for (const auto &term : num_word_mapping) {
      const auto &num = term.first;
      const auto &words = term.second;
      std::cout << "words of " << num << " is [";
      for (const auto &word : words) {
        std::cout << word << ", ";
      }
      std::cout << "]\n";
    }

    return num_word_mapping[num];
  }
};
