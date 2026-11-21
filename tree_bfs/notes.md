# Tree BFS (Level Order)

## Signals
- Level-by-level traversal, printing, or grouping.
- Shortest path or minimum steps in unweighted trees or graphs.
- Boundary or horizontal tree views (left, right, top-down).

## Useful Observations
- **Snapshot Queue Size for Level Isolation**: Always freeze the queue size `int sz = q.size()` before the inner loop; this processes nodes strictly one level at a time without mixing generations.
- **Shortest Path Guaranteed**: In unweighted graphs and trees, the first time BFS reaches a target node is guaranteed to be the shortest path in terms of edge count.
- **Zigzag via Flag or Deque**: Instead of complicated pointer manipulations, alternate a boolean flag `isReverse` every level and reverse the current level vector before storing.
- **Left/Right View from Index**: In a level loop of size `sz`, index `0` is the left view node and index `sz - 1` is the right view node.

## Key Variations
- **Standard Level-by-Level**: Freeze `sz = q.size()` and process inner loop.
- **Zigzag / Alternating Traversal**: Alternate insertion direction or reverse level vectors.
- **Bottom-Up Level Order**: Run standard BFS, then reverse the final 2D result vector.
- **Multi-Source BFS**: Push all initial source nodes into queue at step 0 (e.g. Rotting Oranges).

## Code Skeleton
```cpp
if (!root) return {};
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int sz = q.size(); // Freeze level size!
    for (int i = 0; i < sz; i++) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}
```

## Traps
- **Dynamic Queue Size in Loop**: Writing `for (int i = 0; i < q.size(); i++)` directly will evaluate `q.size()` dynamically as child nodes are pushed, corrupting level boundaries.
- **Missing Root Guard**: Pushing a `nullptr` root causes instant crashes or incorrect level size counts.
- **Visited Set in Graphs**: Trees have no cycles so visited sets are unnecessary; general graphs require marking visited immediately upon pushing to the queue.
