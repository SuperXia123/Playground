#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "solutions/程序员面试金典/面试题03.01.三合一.h"
#include "utils.h"

using namespace std;

int main() {
  TripleInOne triple(18);
  
  PrintValue(triple.peek(1));
  PrintValue(triple.pop(2));
  PrintValue(triple.isEmpty(1));
  triple.push(2, 40);
  PrintValue(triple.pop(2));
  triple.push(0, 44);
  triple.push(1, 40);
  triple.push(1, 40);
  triple.push(1, 40);
  triple.push(1, 40);
  triple.push(1, 40);
  triple.push(1, 40);
  PrintValue(triple.peek(1));
  PrintValue(triple.pop(2));
}
