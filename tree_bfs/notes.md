# Tree BFS (Level Order)

## Signals
- Level-by-level processing or printing.
- Shortest path in unweighted tree or graph.
- Boundary or tree views (left, right, top-down).

## Key Variations
- **Standard Level-by-Level**: Freeze queue size `sz = q.size()` at the start of each level.
- **Zigzag / Alternating**: Use a level counter or deque; reverse collection every other level.
- **Bottom-Up Level Order**: Standard BFS, then reverse the final 2D result vector.

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
- **Dynamic Queue Size**: Never write `for (int i = 0; i < q.size(); i++)` directly; `q.size()` changes as children are pushed.
- **Missing Root Guard**: Always check `if (!root) return;` before pushing to avoid queuing a `nullptr`.
