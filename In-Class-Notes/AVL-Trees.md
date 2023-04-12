## Apr 11, 2023 In-Class Notes

## Self-Balancing Trees
* Self-balancing trees always make sure that a binary search tree is balanced
* If an insert or removal makes the tree unbalanced, then the nodes are rearranged to make them balanced again
* A node rearrangement keeps the sort order, but the nodes are organazied at different positions

## Balance factor
* the balance factor is used to measure how balanced a tree is
* The balance factor is the height difference of its two child subtrees
```
BF(x) = Height(RightSubTree(x)) - Height(LeftSubTree(x))
```

* An AVL tree must have a balance factor of -1, 0, or 1
* In the class, we always use the absolute value of the balance factor, so values must be 0 or 1
* We must rebalance the tree when there is a node that is greater than 1

## Balancing the tree
* When rebalancing a tree, the left to right order must stay the same
* There are four different ways to balance the tree
* We call this rotating
* When we rotate, we change the root node of the subtree
* Its called rotating because we are rearranging pointers
* Once we are done rotating, we should update the balance factors of all the nodes in the branch
* We should move up recursively updating all the balance factors each time we do an insertion and deletion. If we encounter a balance factor greater than 1, then we should balance the tree
* When you are rebalancing the tree, you could create placeholder node pointers to keep track of all the nodes being rotated
* Restructuring the tree takes constant time

* There are four types of rotations:
  * sinle left rotation
  * single right rotation
  * double left rotation
  * double right rotation
  
## AVL Tree Performance
* A single restructure taks **O(1)** time
* ```search```, ```insert```, and ```remove``` take about **O(log n)** time. It is not exactly **O(log n)** because the balance factor is not always 0 in an AVL tree
