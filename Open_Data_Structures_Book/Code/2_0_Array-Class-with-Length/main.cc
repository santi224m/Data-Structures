#include <iostream>

#include "array.h"

int main() {
  Array<int> arr1 = Array<int>(3);
  arr1[0] = 2;
  arr1[1] = 4;
  arr1[2] = 8;
  std::cout << "Array Size: " << arr1.GetSize() << std::endl;
  for (size_t i = 0; i < arr1.GetSize(); ++i) {
    std::cout << i << " : " << arr1[i] << std::endl;
  }
  return 1;
}


// Output
// Array Size: 3
// 0 : 2
// 1 : 4
// 2 : 8