#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题16.02.单词频率.h"
#include "utils.h"

using namespace std;

int main() {
  WordsFrequency word_frequency_ipl({"i", "have", "an", "apple", "he", "have", "a", "pen"});


  auto ret = word_frequency_ipl.get("pen");
  PrintValue(ret);
}
