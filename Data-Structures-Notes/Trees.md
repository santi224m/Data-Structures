# Chapter 6 - Trees
* A tree is a non-empty set. One element is designated at the root of the tree while all other elements are partitioned into non-empty sets and are subtrees of the root
* Each element in the tree is a tree node
* Tree nodes have various properties:
  * The **depth** of a node is the number of edges from the root to that node
  * The **height** of a node is the longest path from that node to one of its leaves
  * The height of a tree is the height of its root since it is the node with the biggest height
* A **leaf node** is a node that has no childer. Its only path is up to its parent node
* In this section we will review 2 types of trees:
  * Binary Trees - Each node has zero, one, or two children. Operations on binary trees are simple and efficient
  * Binary Search Trees - A binary tree where every left child node has a value less than its parent node and every right child node has a value greater than or equal to its parent node

## Traversal
* There are times when we must visit every node in the tree. This means we perform some type of operation on every node. There are several systematic ways to do this:
  * **preorder** - Current node, left subtree, right subtree (DLR)
  * **postorder** - Left subtree, right subtree, current node (LRD)
  * **in-order** - Left subtree, current node, right subtree (LDR)
  * **levelorder** - Level by level, from left to right, starting from the root node

## Sample implementations for Tree Traversal
```cpp
preorder(node) {
  visit(node);
  if (node.left) preorder(node.left);
  if (node.right) preorder(node.right);
}
```

```cpp
inorder(node) {
  if (node.left) inorder(node.left);
  visit(node);
  if (node.right) inorder(node.right);
}
```

```cpp
postorder(node) {
  if (node.left) postorder(node.left);
  if (node.right) postorder(node.right);
  visit(node);
}
```

```cpp
levelorder(root) {
  Queue<Node> q;
  q.push(root);
  while (!q.empty()) {
    Node current = q.pop();
    visit(current);
    if (current.left) q.push(current.left);
    if (current.right) q.push(current.right);
  }
}
```

* Example of each type of Tree Traversal on example tree
```
// Tree Visualization
        50
  30	      90
20  40		100
```
```
preorder
50 30 20 40 90 100
```
```
inorder
20 30 40 50 90 100
```
```
postorder
20 40 30 100 90 50
```
```
levelorder
50 30 90 20 40 100
```

## Balancing
* When elements that are already sorted are stored in a tree, all elements will go the same route, and the tree will look more like a list than a tree
  * This kind of tree is known as a degenerate tree
* To fix this, we need balancing routines, which will make sure that under all branches are an equal number of elements
* Balancing routines are important to maintain optimal speed
* In a degenerate tree with *n* elements, the longest path will be *n* nodes long, whereas in a balanced tree the longest pasth would be log *n* nodes
