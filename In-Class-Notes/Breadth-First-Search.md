# Breadth-first search (May 9, 2023)

* Note: Study DFS and BFS pseudocode for final

**Breadth-frst search** - Finds a path between two nodes by taking one step down from all paths and immediately backtracking

* BFS always returns the shortest path
* Pen Ultimate data structure is a data structure that allows us to remember the predecessor of each node

```cpp
std::unordered_map<Node, Node> penultimate;

//Ex: The predecessor of D is H
penultimate[H] = D;
```

**BFS Pseudocode**

```cpp
function bfs(v1, v2):
     queue := {v1}.
     mark v1 as visited.

     while queue is not empty:
         v := queue.removeFirst().
         if v is v2:
             a path is found!
             reconstruct path from v1 to v2 using penultimate data structure

         for each unvisited neighbor n of v:
             mark n as visited.
             queue.addLast(n).
             update penultimate data structure

     // path is not found.
```

* The Queue if FIFO
* The penultimate data structure stores information on how each node was reached
* Once a path is found, the code looks at the penultimate data structure to rebuild the path

Create temp node
```cpp
tempNode = c;
if tempNode = beginning THEN BREAK;
push tempNode to final path
tempNode = penultimate[tempNode];

END WHILE
```