# Chapter 3 - List Structures and Iterators

* Both arrays and node chains allow us to store an ordered sequence of elements
* With an array, we can use ```get-element()``` and ```set-element()```
* With a node chain, we must use ```get-next()``` until we find the element we are looking for and then use ```get-value()``` and ```set-value()``` to access the element
* A **List** is an Abstract Data Type (ADT)

#### List Interfaces
```
List<item-type> ADT

get-begin() returns List Iterator<item-type>
// Returns a list iterator that represents the first element in the list
// O(1)

get-end() returns List Iterator<item-type>
// Returns a list iterator that represents one element past the last element in the list
// O(1)

prepend(item-type newItem)
// Adds a new element at the beginning of the list
// O(1)

insert-after(List Iterator<item-type> iter, item-type newItem)
// Adds a new element after iter
// O(n)

remove-first()
// Removes the element at the beginning of the list
// O(1)

remove-after(List Iterator<item-type> it)
// Removes the element after it
// O(n)

is-empty() returns bool
// Returns true if there are no elements in the list, false otherwise
// O(1)
// Default implementation

get-size() returns int
// Returns the number of elements in the list
// O(n)
// Default implementation

get-nth(int n) returns item-type
// Returns the nth element in the list, starts counting from 0
// O(n)
// Default implementation

set-nth(int n, item-type newItem)
// Assigns a new value to the nth element, starts counting from 0
// O(n)
// Default implementation
```
* An **iterator** is also an Abstract Data Type
* It allows access to a single element or incremental movement around the list
* All operations from the List Iterator below run in **O(1)**
* The ```get-end()``` interface in List returns an iterator to one element after the last element in the list
* This allows us to loop through a list by checking whether the current iterator is equal to the iterator returned by ```get-end()```

#### Iterator Interfaces
```
List Iterator<item-type> ADT

get-value() returns item-type
// Returns the value of the element that this iterator refers to

set-value(item-type newValue)
// Assigns a new value to the element that this iterator refers to

move-next()
// Makes iterator refer to the next element in the list

equal(List Iterator<item-type> other-it) returns bool
// Returns true of the other iterator refers to the same element as this iterator, false otherwise
```

#### Default Implementations of List

```
abstract type List<item-type>

method is-empty()
  return get-begin.equal(get-end())
end method

method get-size() // returns int
  int size = 0
  List Iterator<item-type> iter = get-begin()
  while (iter != get-end())
    ++size
    iter.move-next()
  end while
  return size
end method

// find-nth is used by get-nth() and set-nth()
helper method find-nth(int n) // returns List Iterator<item-type>
  if (n >= get-size()
    throw error "Index is past the end of list"
  end if
  List Iterator<item-type> iter = get-begin()
  while (n > 0)
    iter.move-next()
    --n
  end while
  return iter
end method

method get-nth(int n) // returns item-type
  return find-nth(n).get-value()
end method

method set-nth(int n, item-type newValue)
  find-nth(n).set-value(new-value)
end method

end type
```
* Some interfaces in the List ADT have default implementations. These implementations use other more primitive implementations
* These default implementations can be implemented with better running times for certain kinds of lists

## Implementations
* There are two standard data types that implement a List
  * A node chain, also called a Singly Linked List
  * A Vector, which is an extension of the array that automatically resizes itself when needed
* A Singly Linked List inherits the default implementations from List

#### Singly Linked List Implementation
```
type Singly Linked List<item-type> implements List<item-type>
  data Node<item-type> head  // refers to the first Node in the list; null when empty
  constructor()
    head = null;  // the list is empty when created
  end constructor
  
method get-begin() // returns Iterator<item-type>
  return new SLL-Iterator(head)
end method

method get-end() // returns Iterator<item-type>
  return new SLL-Iterator(null)
end method

method prepend(item-type newItem)
  head = make-node(newItem, head)  // the new node points to the current head as its next element
end method

method insert-after(SLL Iterator<item-type> iter, item-type newItem)
    // Orignal Node --> Next Node
  Node<item-type> newNode = make-node(newItem, iter.node().get-next())
    // Orignal Node --> Next Node
    // New Node --> Next Node
  iter.node.set-next(newNode)
    // Original Node --> New Node --> Next Node
end method
  
method remove-first()
  head = head.get-next()
end method

// This method removes the node after the current node by pointing the current
// node to the node two nodes down
// Node 1 --> Node 2 --> Node 3
// remove-after(Node 1)
// Node 1 --> Node 3
method remove-after(SLL Iterator<item-type> iter)
  iter.node.set-next(iter.node.get-next().get-next()
end method

end type
```

* The implementation of ```get-end()``` returns an iterator set to ```null``` because this is the value you get when you run ```get-next``` on the last node in the list
* You can make ```get-size()``` have a running time of **O(1)** by adding a variable that keeps track of the size. Otherwise, you can use the default implementation of ```get-size()```, which runs in **O(n)**

#### SLL Iterator Implementation
```
type SLL Iterator<item-type>

data Node<item-type> node_  // reference to a node in a SLL

constructor(Node<item-type> node)
  node_ = node
end constructor

method get-value() // returns item-type
  return node_.getValue()
end method

method set-value(item-type newValue)
  node_.set-value(newValue)
end method

method move-next()
  node_ = node_.get-next()
end method

// Here we assume the system knows how to compare nodes for equality; pointer comparison
method equal(List Iterator<item-type> other-iter) // returns bool
  return node_ == other-iter.node
end method

end type
```
* An iterator for a SLL consists of a reference to a node in the list
* Most of the operations pass through to the node

## Vector

#### Vector Iterator Implementation
```
type Vector Iterator<item-type>

data Array<item-type> array
data int index

constructor (Array<item-type> my_array, int my_index)
  array = my_array
  index = my_index
end constructor

method get-value() // returns item-type
  return array.get-element(index)
end method

method set-value(item-type newValue)
  array.set-value(index, newValue)
end method

method move-next()
  ++index
end method

method equal(List Iterator<item-type> other-iter) // returns bool
  return array == other-iter.array && index == other-iter.index
end method

end type
```
* The ```equal``` method returns true when both the arrays and the indexes are the same, false otherwise

#### Vector Implementation
// Will Finish Later

## Bidirectional Lists
* Bidirectional Lists allow us to move backwards as well

#### Bidirectional List Interfaces
```
Bidirectional List<item-type> ADT

get-begin() returns BL Iterator<item-type>
// Returns an iterator to the first element in the list
// O(1)

get-end() returns BL Iterator<item-type>
// Returns an iterator the represents 1 element past the last element in the list
// O(1)

insert(BL Iterator<item-type> iter, item-type newItem)
// Adds a new item before iter
// O(n)

remove(BL Iterator<item-type> iter)
// Removes the element reffered to by iter. After the call, iter refers to the next element on the list
// O(n)

is-empty() returns bool
// Returns true if there are no elements in the list, false otherwise
// O(1)
// Default Implementation

get-size() returns int
// Returns the number of elements in the list
// O(n)
// Default Implementation

get-nth(int n) returns item-type
// Returns the nth element in the list counting from 0
// O(n)
// Default Implementation

set-nth(int n, item-type newValue)
// Assigns a new value to the nth element in the list counting from 0
// O(n)
// Default Implementation
```

#### Bidirectional List Iterator Interfaces
```
Bidirectional List Iterator<item-type> ADT

get-value() returns item-type
// Returns the value of the element that this iterator refers to. Returns undefined if the iterator is past the end of the list

set-value(item-type newValue)
// Assigns newValue to the element that this iterator refers to. Undefined if the iterator is past the end

move-next()
// Makes the iterator refer to the next element in the list. Undefined if iterator is past the end

move-previous()
// Makes the iterator refer to the previous element in the list. Undefined if the iterator points to the first element in the list

equal(List Iterator<item-type> other-iter) returns bool
// Returns true if the other iterator refers to the same element as this iterator, false otherwise
```
* All operations for the Bidirectional List Iterator run in **O(1)**

## Tradeoffs
* We must decide what data stuctures to use based on what we will be doing with the data
* We must choose a data structure that allows us to do everything we have to do in a way that isn't too slow for any of the operations we must perform
  * If a data structure is quick for one of the operations it must perform, but slow for a different operation it must perform, then we should not use it no matter how fast the quick operation is
  * We must instead look for a more balanced operation that performs all operations in a decent amount of time
* Often the simplest solution will be to use a linear array
* Keeping our data as an ADT allows us to easily switch to another data structure and measure which is slower or faster

## Advantages / Disadvantages

* Array Advantages
  * You can access an element using an index, which is faster
* Linked List Advantages
  * You can change the size of the array easily
  * You can insert an element anywhere in the list without having to shift any elements
