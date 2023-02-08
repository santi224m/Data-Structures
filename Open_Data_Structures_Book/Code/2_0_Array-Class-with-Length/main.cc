#include <iostream>

#include "array.h"

int main() {
  Array<int> arr1 = Array<int>(3);
  arr1[0] = 2;
  arr1[1] = 4;
  arr1[2] = 8;
  std::cout << "arr1 Size: " << arr1.GetSize() << std::endl;
  for (size_t i = 0; i < arr1.GetSize(); ++i) {
    std::cout << i << " : " << arr1[i] << std::endl;
  }

  Array<int> arr2 = Array<int>(5);
  arr2 = arr1;
  std::cout << "arr2 Size: " << arr2.GetSize() << std::endl;
  arr2[2] = 93;
  for (size_t i = 0; i < arr2.GetSize(); ++i) {
    std::cout << i << " : " << arr2[i] << std::endl;
  }
  return 1;
}


// Output
// arr1 Size: 3
// 0 : 2
// 1 : 4
// 2 : 8
// arr2 Size: 3
// 0 : 2
// 1 : 4
// 2 : 93