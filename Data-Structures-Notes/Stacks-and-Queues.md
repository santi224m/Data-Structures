# Chapter 4 - Stacks and Queues

## Stacks
* A stack is a basic data structure where insertion and deletion only happens on one end of the stack, known as the top of the stack
* A stack data structure is like a stack of plates, where if you want to get to a certain plate, you have to remove the plates on top of that plate first
* An implementation of a stack is also called LIFO (Last In First Out)
* There are three operations in a stack:
  * push - Inserting an element into the stack
  * pop - Removing an element from the stack
  * pip - Displaying the elements from the stack

Operations of a **stack data type**
```
Stack<item-type>

push (new-item :item-type)
// Adds an item to the stack

top () :item-type
// Returns the last item pushed on to the stack

pop ()
// Removes the last item pushed on to the stack

is-empty () :Boolean
// Returns true if no more items can be poped and there is no top item, false otherwise

is-full () :Boolean
// Returns true if no more items can be pushed, false otherwise

get-size () :Interger
// Returns the number of elements in the stack
```
  * All operations in Stack run in **O(1)** except for ```get-size()```, which runs in **O(n)**

## Linked List Implementation of a Stack
* You can implement a stack using a Linked List to store the elements
* The stack usings the Linked List's interfaces to manage the stack
* You could also implement the Stack from scratch if you want it to be more optimized

**Implementation of a Stack Using a Linked List**
```
type Stack<item-type>
data list = Singly-Linked-List<item-type>

constructor()
  list = new Singly-Linked-List()
end constructor

method push(new-item:item-type)
  list.prepend(new=item)
end method

method top() :item-type
  return list.get-begin().get-value()
end method

method pop()
  list.remove-first()
end method

method is-empty() :Boolean
  return list.is-empty()
end method

method is-full() :Boolean
  return false // Linked List don't have a size limit
end method

method get-size() :Interger
  return list.get-size()
end method

end type
```

### Performance Analysis
#### Linked List Implementation
* Accessing the first element and checking for emptiness runs in **O(1)**
* The ```get-size()``` operation is rarely used in a stack, so it is fine to leave its running time as **O(n)**. This could be changed to **O(1)** by creating a variable that keeps track of the size if needed
#### Array Implementation
* The array implementation keeps the bottom of the stack at the beginning of the array and grows it to the end of the array
* This is because removing an element from the beginning of an array runs in **O(n)** since you need to shift all the elements to the right
* Removing an element from the end of the array runs in **O(1)**
* It is better to use a vector instead of an array for a Stack because an array has a size limit
* All operations run in **O(1)** except for the ocasional push that has to resize the vector

### Applications of Stacks
#### Converting a Decimal Number into a Binary Number
* To convert from decimal to binary, you use the following algorithm
```cpp
int decimal = SOME_DECIMAL_NUMBER;
while (decimal > 0) {
  std::cout << decimal % 2;
  decimal /= 2;
}
// Prints binary number in reverse order
```
* We can use a stack to reverse the order that the binary number is printed to fix this issue
```cpp
Stack storeBinaryDigits;
int decimal = SOME_DECIMAL_NUMBER;
while (decimal > 0) {
  storeBinaryDigits.push(decimal % 2);
  decimal /= 2;
}

while (!storeBinaryDigits.empty()) {
  std::cout << storeBinaryDigits.top();
  storeBinaryDigits.pop();
}
// Prints binary number in correct order
```

## Queues
* A queue is a basic data structure. The first element to be inserted into the queue is the first one to be removed (FIFO)

```
Queue<item-type> Operations
enqueue (newItem :item-type)
// Adds an item to the end of the queue

front () :item-type
// Returns item at the front of the queue

dequeue ()
// Removes item at the front of the queue

is-empty () :Boolean
// Returns true if no more items can be dequeued and there is no front, false otherwise

is-full () :Boolean
// Returns true if no more items can be enqueued

get-size () :Integer
// Returns the number of elements in the queue
```
  * All operations run in **O(1)**, except ```get-size()```, which runs in **O(n)**

```cpp
template <typename T>
class Queue {
 private:
  Singly_Linked_List<T> list;
  Singly_Linked_List<T>::Iterator tail;
  
 public:
  // Constructor
  Queue() {
    list = new Singly_Linked_List<T>();
    tail = list.begin();
  }
  
  void enqueue(T newItem) {
    if (is-empty()) {
      list.prepend(newItem);
      tail = list.begin();
    } else {
      list.insert_after(newItem, tail);
      ++tail;
    }
  }
  
  T front() {
    return list.begin().getElement();
  }
  
  void dequeue() {
    list.remove-first();
    if(is-empty()) {
      tail = list.begin();
    }
  }
  
  bool is-empty() {
    return list.is-empty();
  }
  
  // Liked list are limitless in size, so is-full() should return false
  bool is-full() {
    return false;
  }
  
  int get-size() {
    return list.get-size();
  }
}
```
* When you want to enqueue an new item, the new item should point to the current tail as it's next. The tail should then be updated to point to the new item. This doesn't work if the list was empty.
* In a linked list, access to the first element runs in **O(1)** because the head pointer always points to the first element. This means that ```enqueue```, ```front```, and ```dequeue``` all run in **O(1)**
* ```is-empty``` also runs in **O(1)**
* The running time of ```get-size``` depends on how the linked list implemented its ```get-size``` method. ```get-size``` isn't used often in a queue, so it is fine to leave it unoptimized in order to save space

## Deqeue
* A deqeue is similar to a queue, but insertions and deletions can be done at both ends of the queue.
* It is known as a double ended queue
* Deque has two types:
  * Input restricted queue - Insertion can only be done on one end of the queue
  * Output restricted queue - Output can only be done on one end of the queue
