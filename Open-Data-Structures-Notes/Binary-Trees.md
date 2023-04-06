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
  * Whether you uses external nodes a placeholders can depend on the alorithims that you will be implementing and on personal preference
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
* To find the size of a binary tree, we start at the root node and find the size of its left child and right child. We do this recursively for a nodes and then add 1 to the result to account for the root node
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
* In the base case, we return -1 when the node points to nullptr because the height doesn't include the original node. So for example, if the node input into the function was a lead, there would be 1 node total, but the height would be 0. Returning -1 ensures that the final height returned is correct

