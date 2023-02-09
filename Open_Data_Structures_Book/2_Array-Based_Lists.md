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

## ArrayStack: Fast Stack Operations Using an Array

* An ArrayStack implements the list interface using an array ```a```
* the element with index ```i``` is stored at ```a[i]```
* ```a``` is usually larger than the elements it is storing, so we use ```n``` to keep track of the amount of elements in the array
* Elements are stored in ```a[0]...a[n-1]```
* ```a.length``` is always greater than or equal to ```n```

```cpp
Array<T> a;
int n;  // keeps track of amount of elements in array
int size() {
  return n;
}
```

### The Basics

* Accessing and modifying the elements of the array is easy
* We simply change the value of ```a[i]```
* We should do some bounds-checking before applying any changes

```cpp
// get function
T get(int i) {
  return a[i];
}
// set function
T set(int i, T x) {
  T y = a[i];  // we want to return current value of a[i]
  a[i] = x;
  return y;
}
```

* For the ```add(i,x)``` function, we have to check that the array has enough space for the new element
  * check if ```n``` is equal to the array length
  * If the array is full, we must use the ```resize()``` function to increase its capacity
* After making sure that there is enough space in the array for the element, we have to shift all the elements from ```a[i]...a[n-1]``` to the right by one position, set ```a[i]``` equal to the new element, and increase ```n``` by 1

```cpp
void add(int i, T x) {
  if (n + 1 > a.length) resize();
  for (int j = n; j > i; j--) {  // shift elements to the right
    a[j] = a[j - 1];
  }
  a[i] = x;
  n++;
}
```
* The cost of running the above operation is proportional to the amount of elements we have to shift
  * We are not taking into consideration the potential cost of running the ```resize()``` function
* This operation has a running time of **O(n-i)**
* For the ```remove(i)``` function, we shift the elements ```a[i+1]...a[n-1]``` one position to the left, overwriting the element that we are removing
* We have to decrease the value of ```n``` by 1
* We also check if our value of ```n``` is a lot smaller than the length of the array, and if it is we run the ```resize()``` function to shrink the array
* Finally, we return the value of the element we removed
```cpp
T remove(int i) {
  T x = a[i];  // we will return the value of the element we remove
  for (int j = i; j < n - 1; ++j) {  // shift elements 1 position to the left
    a[j] = a[j + 1];
  }
  n--;
  if (a.length >= 3 * n) resize();  // resize if elements stored is a lot smaller
                                    // than array length
  return x;
}
```
* The cost of running this operation is the same as running the ```add(i, x)``` operation
  * The running time is proportional to the amount of elements we shift
  * The running time is **O(n-i)**
  
### Growing and Shrinking

* Here is what the ```resize()``` function does
  * It allocates a new array ```b``` with a size of ```2n```
  * It copies the first ```n``` elements in ```a``` to ```b```, which is all the elements
  * It sets ```a``` equal to ```b```
* After running the ```resize()``` function on ```a```, its size is ```2n```

```cpp
void resize() {
  array<T> b(std::max(2 * n, 1));
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
  }
  a = b;
}
```

* The cost of running the above operation is **O(n)**
* We analyze the cost of ```resize()``` using *amortized analysis*
  * This means that we don't calculate the cost of ```resize()``` every time that the ```add(i,x)``` and ```remove(i)``` functions are called, instead we calculate the total cost of ```resize()``` over a sequence of ```m``` calls to ```add(i,x)``` and ```remove(i)```
  * We do this because ```resize()``` isn't called everytime the ```add(i,x)``` and ```remove(i)``` functions are called
  
### Summary
* An **ArrayStack** implements the **List** interface
* Ignoring the cost of ```resize()```:
  * ```get(i)``` and ```set(i,x)``` run in **O(1)**
  * ```add(i,x)``` and ```remove(i)``` run in **O(1+n-i)**
* Beginning with an empty ArrayStack and and performing a sequence of ```m``` ```add(i,x)``` and ```remove(i)``` operations results in a running time of **O(m)** for all calls to ```resize()```
* The ArrayStack is an efficient way to implement a Stack
* We can implement ```push(x)``` as ```add(n,x)```
* We can implement ```pop()``` as ```remove(n-1)```
* Both these functions will run in **O(1)** amortized time
