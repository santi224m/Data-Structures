# Chapter 2 - Arrays

* Arrays are a collection of elements of similar data types that are stored into a common variable
* Objects in an array are stored linearly in memory
* The elements can be referenced by an index
* Arrays can be multidimensional. When this is the case, you need multiple indices to access an element
* A matrix or tensor both utilize multidimensional arrays
* Here are the interfaces of an array:
```
Array<Element>

make-array(int n) : Array
// Create an array of elements indexed from 0 to n - 1. The size of the array is n.

get-value-at(Array a, int index) : Element
// Returns the value of the element at the corresponding index. The value of 
// index must be between 0 and n - 1

set-value-at(Array a, int index, Element new-value)
// Set the value of the element at the corresponding index to be equal to new-value
```
* Arrays gurantee constant time read and write access. **O(1)**
* Many look up operations are linear time. **O(n)**
* Arrays are efficient becuase computer languages compute the address of an element using the memory address of the first element in the array
* Array implementations differ between languages. Some languages allow you to resize the array and include elements of different types, while other langauges require the size of the array to be known at compile time and require all elements to be of the same type in the array
* Arrays are used in the implementations for many other data structures

## Index Types
* The array index has to be of some type
* The most common type used for an index is an integer, but some languages allow you to use any discrete type as an array index
## Index Bounds
* An array index consists of a range of values with a lower bound and an upper bound
* Some languages set the lower bound as either 0 or 1, and only let you choose the upper bound
* Other languages let you choose both the lower and upper bound, including negative numbers
## Index Bounds Check
* An aspect of an array index is the check for valid ranges of indices and what happens when an invalid index is accessed
* Many computer viruses attack by using invalid array bounds
* There are three ways in which invalid indexes are handled:
  1. Most languages will give an error when the index is out of bounds
  2. Some languages will not check the bounds and will return some arbitrary value, including c++
  3. Some languages, mostly scripting languages, will automatically expand the array to allow the data to be added to the array
## Declaring Array Types
* The way you declare an array depends on the languages
* For languages that only allow you to set the array size and element type, it can be simple
* Declaring arrays can be more complex in languages that allow you to set the lower bound, upperbound, size, and element type
## Array Access
* You usually access an array with the array name and some brackets, square, or parenthesis
* The following code accesses the fourth element of an array called **august**. This code is for the C programming language, which starts the index at 0.
  ```
  august[3]
  ```
* We use indexes to store related data
* Using indexes allows us to iterate through the whole array and access all the data
