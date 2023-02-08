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
