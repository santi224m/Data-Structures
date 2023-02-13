# Chapter 2 - Array-Based Lists

* In this chapter we will study the implemtations of the list and queue interfaces
  * These interfaces use what is called a backing array to store their data
* Following are the running times for operations we will use on these data structures:

  |  | get(i)/set(i,x) | add(i,x)/remove(i) |
  | --- | --- | --- |
  | ArrayStack  | O(1) | O(n-i) |
  | ArrayDeque | O(1) | O(min{i,n-1}) |
  | DualArrayDeque | O(1) | O(min{i,n-i}) |
  | RootishArrayStack | O(1) | O(n-i) |

* Data structures that use arrays to store data have many similarities:
  * Arrays allow you to access its contents in constant time. This is why the **get(i)/set(i,x)** operations run in constant time for all the operations in the table above
  * When you have to add or remove an element that is not at the end of the array, all the other elements have to be shifted. This is why the running times for the **add(i,x)/remove(i)** operations depend on the number of elements and the index of the element
  * Arrays cannot change their size, so every time you need to store more data than the array can hold, you have to create an array of the size you need and then copy all the elements from the old array to the new one. This can be an expensive operation
* The running times in the table above do not include the cost of growing or shrinking the array
  * This is because the cost of growing or shrinking an array is **O(1)** when amortized over all *m* operations, where *m* is a sequence of operations
* It can be useful for arrays to keep track of their size
  * In c++, arrays don't do this by default, but we can create an array class that keeps track of its size
* Below is an example implementation of an array class that keeps track of its length
```cpp
// Array.h
template <class T> 
class Array {
 public:
  Array(int len) {
    length_ = len;
    a = new T[len];  // create an array of type T with a size of length
  }
  int GetSize() const {
    return length_;
  }
  T& operator[](int i) {  // elements can be indexed
    if (i >= 0 && i < length_) {
      return a[i];
    }
  }
  Array<T>& operator=(Array<T> &b) {
    if (a != NULL) delete[] a;  // delete array a if it already exists
    a = b.a;
    b.a = NULL;
    length_ = b.GetSize();
    return *this;
  }

 private:
  T* a;
  int length_;
};
```

```cpp
// main.cc
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
```
