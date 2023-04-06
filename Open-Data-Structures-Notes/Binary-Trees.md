# Chapter 6 - Binary Trees
* Binary trees are one of the most fundamental structures in Computer Science
* Mathematically, a binary tree is a connected, undirected, finite grapsh with no cycles and no vertex of degree greater than three
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
