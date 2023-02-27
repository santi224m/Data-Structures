## Feb 23, 2023 In-Class Notes

# Linked Lists
* Linked lists are composed of nodes and pointers that point to other nodes
* Nodes in a Singly-Linked (SLL) Lists only point to the next node
* SSL have a head and a tail. The head points to the first node in the list and the tail points to the last node in the list
* The last node points to ```nullptr``` to show that it is the last node
* When there is an empty list, pHead and pTail point to ```nullptr```
* If there is only 1 element in the list, both pHead and pTail point to the element
* SSL has a size member variable to keep track of nodes
* **push_front()** has **O(1)**
  * Create Node
  * Set pointer for Head pointer
  * Set Head pointer to new note
* Removing item from front has **O(n))**
  * You have to travers the whole list to know where to point the tail

* You can make your own namespaces so that the code that you make doesn't conflict with code from libraries that you might be using
```cpp
// Lib.hpp
namespace Lib {
  class MyClass {
    // some code
  }
}

// main.cpp
#include "Lib.hpp"

int main() {
  Lib::MyClass mc1;  // use MyClass from Lib.hpp
}
```
* You can nest namespaces

* const pointers can change their values(the object they point to), but not the value of the objects that they point to
  * They can only use ```const``` member functions

### Inserting a node at the Head
* Allocate a new node
* Insert the new element in the node
* New node points to old head
* Head pointer points to new node

### Inserting node at the Tail
* Allocate new node
* Insert element to node
* New node points to nullptr
* Old tail node points to new tail node
* Update tail pointer to point to new tail

### Iterating through linked list
```cpp
for (Node<T>* cursor = this->head_; cursor->getNext() != nullptr; cursor = cursor->getNext()) {
  // some code
}
```
