# Chapter 6 - Binary Trees
* Binary trees are one of the most fundamental structures in Computer Science
* Mathematically, a binary tree is a connected, undirected, finite graph with no cycles and no vertex of degree greater than three
* In Computer Science, most binary tree applications are rooted
* A **root** is a special node with a degree of at most two
* For every node ```u``` that is not the root, the second node on the path from ```u``` to the root is the parent of ```u```
* All other nodes adjacent to ```u```, not including the parent, are children of ```u```
* Most binary trees we discuss are ordered, so we disinguish between the left child and right child of a node
## Terminalogy used for binary trees
* **depth** - The depth of a node is the length of the path from the node to the root
* If the node ```w``` is on the path from the node ```u``` to the root, then ```w``` is said to be an **ancestor** of ```u``` and ```u``` is a **descendant** of ```w```
* The **subtree** of a node ```u``` is the binary tree where ```u``` is the root and it contains all of ```u```'s descendants
* The **height** of a node is the longest path from the node to one of its descendents
* The height of a tree is the height of the root
* A node is a **leaf** if it has no children
* In some cases, **external nodes** can be used as placeholders to show that a node has no children
  * Using external nodes in this manner can help simplify algorithims used on the tree because it removes the need to check for cases where a node has no left child or right child
  * Whether you use external nodes as placeholders can depend on the algorithms that you will be implementing and on personal preference
  * A binary tree with n >= 1 real nodes has n+1 external nodes
  
# BinaryTree: A Basic Binary Tree
* To represent a node in a binary tree, you should store its neighbours (at most three) like so:
```cpp
class BTNode {
 N *left;
 N *right;
 N *parent;
 // CTOR
 BTNode() {
   left = right = parent = nullptr;
 }
}
```
* When one of the neighbours doesn't exist, we set it equal to ```nullptr```
* The binary tree can be represented with a pointer to its root node
```cpp
Node *r; // root node
```

* We can compute the depth of a node by counting the number of nodes that need to be traversed to get to the root node
```cpp
int depth(Node *currentNode) {
  int depth = 0;
  while (currentNode != rootNode) {
    currentNode = currentNode->parent;
    depth++;
  }
  
  return depth;
}
```

## Recursive Algorithms
* We use recursive alorithms to find details about binary trees

#### Compute the size of a binary tree
* To find the size of a binary tree, we start at the root node and find the size of its left child and right child. We do this recursively for all nodes and then add 1 to the result to account for the root node
```cpp
int size(Node *root) {
  // Base case
  if (root == nullptr) return 0;
  // Recursive case
  return 1 + size(root->left) + size(root->right);
}
```
#### Compute height of a node
* To compute the height of a node, we take the max height of the nodes subtrees and then add 1 to account for the current node
```cpp
int height(Node *currentNode) {
  // Base case
  if (currentNode == nullptr) return -1;
  // Recursive case
  return 1 + max(height(currentNode->left), height(currentNode->right));
}
```
* In the base case, we return -1 when the node points to ```nullptr``` because the height doesn't include the original node. So for example, if the node input into the function was a lead, there would be 1 node total, but the height would be 0. Returning -1 ensures that the final height returned is correct

## Traversing Binary Trees
* While it is possible to traverse a tree using recursion, this isn't ideal because if the tree has a height that is too big, traversing the tree recursively will take up too much space on the stack, and could even cause the program to crash
* To traverse a tree without recussion, you must use an algorithm that decides where to go next based on where it came from
* The algorithm works like this:
  * If we arrive at a node from its parent, then the next step is to visit the nodes left child
  * If we arrive at a node from its left child, then the next step is to visit the nodes right child
  * If we arrive at a node from its right child, then we are done visiting the nodes subtree. The means the next step is to visit the nodes parent
* Below is c++ code that implements this algorithm
```cpp
void traverse() {
  Node *cursor = root;
  Node *prev = nullptr;
  Node *next = nullptr;
  while (cursor != nullptr) {
    // Check if node arrived from parent
    if (prev == cursor->parent) {
      if (cursor->left) {
        next = cursor->left
      } else if (cursor->right) {
        next = cursor->right;
      } else {
        next = cursor->parent;
      }
    } else if (prev == cursor->left) {  // Check if node arrived from its left child
      if (cursor->right) {
        next = cursor->right;
      } else {
        next = cursor->parent;
      }
    } else {  // Node arrived from node's right child
      next = cursor->parent;
    }
    
    prev = cursor;
    cursor = next;
  }
}
```
* We can also use algorithms to compute the problems we implemented recusively in the section above: ```size()``` and ```height()```
  * This way we don't have to take up as much memory on the stack
* To implement the ```size()``` function with an algorithm, we would use the same code as the ```traverse()``` function, but would use a variable to keep track of the nodes we have visited and increment the variable each time we visit a parent node
* During a **breadth-first** traversal, nodes in a tree are visited level by level, from left to right
  * This type of traversal uses a queue to keep track of nodes and their order
* Below is the c++ code for a breadth-first traversal
```cpp
void bfTraversal() {
  ArrayQueue<Node*> q;
  if (root) q.add(q.size(), root);
  while(q.size() > 0) {
    Node *cursor = q.remove(q.size() - 1);
    if (cursor->left) q.add(q.size(), cursor->left);
    if (cursor->right) q.add(q.size(), cursor->right);
  }
}
```

# BinarySearchTree: An Unbalanced Binary Search Tree
* Each node ```x``` in a binary search tree contains a value ```u.x```
* The value stored in the node ```u.left``` and the values of every node in ```u.left```'s subtree is always less than ```u.x```
* Likewise, the value store in the node ```u.right``` and its subtree are always greater than ```u.x```

## Searching
* The properties of a binary search tree allow for quick search operations
* Following is the procedure for searching through a binary search tree:
  * Start at the root of the binary seach tree and traverse the tree until you find what you are searching for or come to the end of the tree
  * Examine each node you traverse. There are three possibilities when you traverse the tree
  * ```x``` is the value we are searching for. ```u``` is the node being examined
    1. If ```x < u.x```, the search proceeds to ```u.left```
    2. If ```x > u.x```, the search proceeds to ```u.right```
    3. If ```x == u.x```, then we have found the node containing ```u.x```
  * We finish the search when case 3 occurs, or when ```u.x == nullptr```
  
```cpp
T findEQ(T searchVal) {
  Node *cursor = rootNode;
  while (cursor != nullptr) {
    int comp = compare(searchVal, cursor->x);
    if (comp < 0) {
      cursor = cursor->left;
    } else if (comp > 0 ) {
      cursor = cursor->right;
    } else {
      return cursor->x;
    }
  }
  
  return nullptr;
}
```

## Addition
* To add a new value to a binary search tree, we first search for the value. If we find it in the tree, then there is no need to add it. If we don't find it, then we add it as a child to the last node that we encountered when searching for the value
```cpp
bool add(T val) {
  Node *p = findLast(val);
  Node *u = new Node;
  u->x = val;
  return addChild(p, u);
}

Node* findLast(T val) {
  Node *cursor = rootNode;
  Node *prev = nullptr;
  while (cursor) {
    prev = cursor;
    int comp = compar(val, cursor->x);
    if (comp < 0) {
      cursor = cursor->left;
    } else if (comp > 0) {
      cursor = cursor->right;
    } else {
      return cursor;
    }
  }
  
  return prev;
}

bool addChild(Node *prev, Node *newNode) {
  if (prev == nullptr) {
    rootNode = newNode;  // inserting into an empty tree
  } else {
    int comp = compare(newNode->x, prev->x);
    if (comp < 0) {
      prev->left = newNode;
    } else if (comp > 0) {
      prev->right = newNode;
    } else {
      return false;  // newNode.x is already in the tree
    }
    newNode->parent = prev;
  }
  nodeCount++;
  return true;
}
```
* The most time consuming part of adding to a binary tree is searching for the value in the binary tree
* The time is proportional to the height of the node being added
* In the worst case, this is equal to the height of the tree

## Removal
* Removing a node can be difficult when the node has two children
* If the node is a leaf, you can simply detach it from its parent
* If the node has one child, you can splice the node by having the nodes parent adopt the nodes child
```cpp
void splice(Node *u) {
  Node *child;
  Node *parent;
  if (u->left !== nullptr) {  // Since we know u only has one child, we check if it is the left or right child
    child = u->left;
  } else {
    child = u->right;
  }
  if (u == rootNode) {
    rootNode = child;
    parent = nullptr;
  } else {
    parent = u->parent;
    if (parent->left == u) {
      parent->left = child;
    } else {
      parent->right = child;
    }
  }
  if (child) {
    child->parent = parent;
  }
  nodeCount--;
}
```

* When the node being removed has two children, we have to do the following
  * Find a node ```w``` that has less than two children and can replace ```u```
  * ```w``` will be the smallest value in the subtree rooted at ```u.right```. In other words, the leftmost node of ```u.right```
  * We use the leftmost node of ```u.right``` because it is guaranteed to only have one child or less. It cannot have a left child
  
```cpp
void remove(Node *u) {
  if (u->left == nullptr || u->right == nullptr) {  // Check if u has less than two children
    splice(u);
    delete u;
  } else {
    Node *w = u->right;
    while (w->left) {
      w = w->left;
    }
    u->x = w->x;  // Replace u's value with w's value
    splice(w);
    delete w;
  }
}
```

## Summary
* The following operations run in **O(n)** time in a binary search tree:
  * ```add(x)```
  * ```remove(x)```
  * ```find(x)```
* The problem with binary search trees is that they can become unbalanced. This is what causes a **O(n))** time
* The solution to this is to implement it in a way where it is always balanced, which bring the complexity to **O(log n)**

## Discussion
* When designing a binary tree, you must decided whether the nodes should have a pointer to their parent
* If we are only traversing down a tree, then a pointer is unnecessary and takes up space
* We do need a parent if we want to traverse the tree without using recursion
* The lack of a parent pointer also makes other operations more difficult
* You can store pointers to the left child, right child, and parent in an array. This way, you can use algebraic expressions in an if statement
