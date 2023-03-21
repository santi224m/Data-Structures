# Chapter 3 - Linked Lists

* A Linked List is a pointer-based data structure. They are made up of nodes that contain the list items
* With a linked list, we lose the ability to access an element using the ```get(i)``` and ```set(i,x)``` operations in constant time that we have in an array based list
* To access an element, we have to traverse the whole list until we get to the element that we want
* The advatage of Linked Lists is that they are more dynamic
  * Elements can be removed or added from anywhere in the list in constant time. There is no need to shift elements, only to change the pointers for the neighboring elements
* Nodes in a Linked List are connected using pointers
* There are two types of Linked Lists:
  * Singly Linked List - The nodes have a pointer to the next node
  * Doubly Linked List- The nodes have pointers to the previous and next node
* A Singly Linked List can be used to implement a queue and a stack with operations in constant time
* A Doubly Linked List is needed to implement a Deque with operations in constant time

## SLList: A Singly-Linked List
* A Singly Linked List is a sequence of nodes
* Each node contains an element and a pointer to the next node
* For the last node in the list, its next pointer points to ```nullptr```

Node Class Implementation in C++
```cpp
template <typename T>
class Node {
 public:
  T element_;  // Node element
  Node *nextP;  // Pointer to next element
  // CTOR
  Node(T el) {
    this->element_ = el;
    this->nextP = nullptr;
  }
};
```

* A Singly Linked List uses variables ```head``` and ```tail``` to keep track of the first and last nodes in the list, as well as a ```size``` variable to keep track of the number of elements in the list
  * This makes the list more efficient since it avoids having to iterate through the list in order to find the first or last node as well as having to iterate through the list to count the number of elements in the list
* A Singly Linked List can efficiently implement a Stack's ```push``` and ```pop``` operations by adding and removing elements at the head of the list
* The ```push()``` operation creates a new Node with its element set equal to the value being pushed to the list. The new Node's next pointer points to the current head of the list. The size of the list is incremented by 1 since there is one new Node in the list. Finally, the head is updated to point to the new Node being pushed to the list
* The ```pop()``` operation first checks that the list is not empty.
* ```pop()``` removes the head node by setting the head pointer equal to the node following the current head node. If the node being removed is the last element in the list, then tail is set equal to ```nullptr```
  * Before setting the head pointer equal to the next node, ```pop()``` creates a temporary variable pointing to the head element being removed. Once the head pointer is changed to the next element in the sequence, the node being removed is deleted using the ```delete``` keyword. This is done to deallocate the memory used for this node and avoid memory leaks.
* Both ```push()``` and ```pop()``` run in **O(1)**

Stack Implementation using a Singly Linked LIst in C++
```cpp
template <typename T>
class SLList {
 public:
 // CTOR
  SLList() {
    this->head_ = this->tail_ = nullptr;
    this->size_ = 0;
  }
 
  T push(T x) {
    Node<T> *newNode = new Node<T>(x);
    newNode->nextP = this->head_;
    this->head_ = newNode;
    if (this->size_ == 0)
      this->tail_ = this->head_;
    this->size_++;
    return x;
  }
  
  T pop() {
    if (this->size_ == 0) throw std::range_error("pop(): Attempting to pop empty list");
    T element = this->head_->element_;
    Node<T> *removeNodeP = this->head_;
    this->head_ = this->head_->nextP;
    delete removeNodeP;
    this->size_--;
    if (this->size_ == 0)
      this->tail_ = nullptr;
    return element;
  }
    
 private:
  Node<T> *head_;
  Node<T> *tail_;
  int size_;
};
```

## Queue Operations
* A Singly Linked List can also be used to implement a queue
* The ```add(x)``` and ```remove()``` operations both run in constant time. The ```remove()``` operation here is similar to the ```pop()``` in the Stack implementation above because it also removes an element from the head of the Singly Linked List.
* The ```add(x)``` operation will differ from the ```push(x)```operation because it adds the node to the tail of the list instead of the head.

Queue Implementation using a Singly Linked LIst in C++ (**remove()** and **add(x)** operations only)
```cpp
  T remove() {
    if (this->size_ == 0) throw std::range_error("remove(): List is empty");
    T element = this->head_->element_;
    Node<T> *removeNodeP = this->head_;
    this->head_ = this->head_->nextP;
    delete removeNodeP;
    this->size_--;
    if (this->size_ == 0)
      this->tail_ = nullptr;
    return element;
  }
  
  bool add(T x) {
    Node<T> *newNode = new Node<T>(x);
    if (this->size_ == 0) {
      this->head_ = newNode;
    } else {
      this->tail_->nextP = newNode;
    }
    this->tail_ = newNode;
    this->size_++;
    return true;
  }
```

## Summary
* A Singly Linked List can implement a Stack and a Queue in constant time for all operations
* It can implement all the operations of a deque in constant time, except for removing from the tail. This is because in order to remove from the tail, the tail has to be updated to the Node preceding the current tail Node. To do this in a Singly Linked List, you would have to traverse the whole list.
* If you want to impelement a deque using a linked list, you must use a Doubly Linked List for efficiency.
