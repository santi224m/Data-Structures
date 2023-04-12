## In-class notes 4/4/23

# Tree Data Structure
* A tree has a root which is the the start of the tree. The tree has no parent node
* Every node in a binary has zero, one, or two children
* Values that are less than a node go to the left side
* Values that are greater than or equal to a node go on the right side

## Searching through a Binary Tree
* When you are searching through a binary tree, every time you continue to the left or right side, you eliminate half of the elements
* This means that searching through a binary tree has a **O(log n)**
  * This only applies to a balanced tree
* When the tree is no longer balanced, the search time starts to worsen
* A tree that is in between a degenerate tree and a balanced tree will have a search time between **O(log n)** and **O(n)**
* **AVL** trees are self-balancing binary trees
* You can use any data type in a binary tree as long as it has the operators to check for less than, equal, and greater than
* You know that an element doesn't exist in a tree when a node's left or right child is empty and the element you are searching for is supposed to be in that direction

## Applications of Binary Trees
* Arithmetic expressions
* Decision processes
* Searching

## Terminalogy
* Tree - An abstract model of a hierarchical structure
* Node - Make up a tree. They have a parent-child relationship with other nodes
* Root - A node without a parent
* Internal node - Node with at least one child
* External node (leaf) - node without children
* Ancestors - Nodes that come before the current node
* Depth of a node - Number of ancestors of current node
* Height of tree - Maximum depth in the tree

```cpp
template <class T>
Node {
  T element_;
  Node<T> *leftChild_;
  Node<T> *rightChild_;
  Node<T> *parent_;
}
```

```cpp
// Add new node to Binary Tree

// Create new node
// Point corresponding existing node to new node as either its left child or right child
// Point new node to existing node as its parent
```

```cpp
// Removing an element from Binary Tree

// Go to element that is being removed
// Move up to its parent
// Set the pointer that points to node being removed to null
// Use delete keyword on node being removed to avoid memory leaks
```
* If the node that you are removing has more than one subtree, then you have to traverse through every node and add it back to the tree where it should be
* One you add the node back, delete one of the nodes since now there are more than one of that node

## Tree Traversal
* There are three types of traversals of a Binary Tree
  * **Preorder** - currentNode -> leftChild -> rightChild
  * **Inorder** - leftChild -> currentNode -> rightChild
  * **Postorder** - leftChild -> rightChild -> currentNode
* It is easiest to define these traversals using recursion
```
PreOrder Algorithm
preOrder(v)
  visit(v)
  for each child w of v
    preorder(w)
```
```cpp
void preorder(Node<T> *ptr) {
  if (ptr == nullptr) return;
  visit(ptr);  // do something with this node
  preorder(ptr->left);
  preorder(ptr->right);
}
```

## Types of trees
* Full
* Complete
* Perfect

## std::map
* The c++ map uses a tree under the hood
