### Level Order Binary-tree traversal 

![image](https://i2.wp.com/algorithms.tutorialhorizon.com/files/2014/11/Level-Order-Traversal-in-Zig-Zag-pattern-OR-Print-in-Spiral.png)


Is an algorithm to traverse each node of the binary tree level by level from the root node to the the deepest nodes.

### How i implemented it ?

After the construction of the binary tree (Creating the data structure & function to insert nodes to it) , i created Queue of binary tree nodes (the data inside the queue is binary-tree-nodes).

The queue construction was using linked-list(the data and pointer to the next node).

### The idea of the algorithm :

We first enQueue the root node of the binary tree into the queue , then while the queue isn't empty we first (print-modify) the enQueued node (the root) then deQueue it from the Queue.

Then we check if this node has childs on the left || right , if true ; we pass recursievely the left || right tree , and do the same process.

### Time complexity :

The algorithm have O(n) time complexity , because if we have n nodes in a tree , we need to visit them all , and if visiting one node take 2ms so we need 2(ms) * n to visit all nodes , so it proportional to n.

