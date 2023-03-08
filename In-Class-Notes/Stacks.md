## Mar 7, 2023 In-Class Notes

# Stacks

* A **stack** is a data structure of ordered entries that can only be accessed at one end, called the top
* Every time you push an element into the stack, it is added to the top of the stack
* A stack is a **LIFO** data structure
* A stack is has a constructor and the following member functions
  * push - Add an item to the stack
  * pop - Remove the top enty
  * top - Get item at the top without removing it
  * empty - Returns true if stack is empty, false otherwise
  * size - Returns the number of items in the stack
  
* **Stack Underflow** - Attempting to remove an element from an empty stack
* **Stack Overflow** - Attempting to insert an element into a full stack

* A **wrapper class** is a class that wraps or encapsulates another class to provide some abstraction when calling the wrapper class
* A wrapper can also be used as an adapter. For example, you can use it to turn JSON to XML format
