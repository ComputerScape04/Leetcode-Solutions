# Tree DFS

## Signals
- Root-to-leaf paths, path sums, or path collection.
- Tree depth, height, or diameter calculations.
- Subtree validation (BST property, symmetry, isomorphism).

## Key Variations
- **Bottom-Up (Postorder)**: Compute left & right subtree results first, then merge at parent (e.g. depth, diameter).
- **Top-Down (Preorder)**: Pass accumulated state (e.g. `remainingSum - root->val`) down to child nodes.
- **Backtracking Path**: Pass `path` vector by reference; `path.push_back(val)` before recursing and `path.pop_back()` after.

## Code Skeleton
```cpp
// Bottom-Up Pattern (Height / Diameter)
int dfs(TreeNode* root, int& maxDiameter) {
    if (!root) return 0;
    int left = dfs(root->left, maxDiameter);
    int right = dfs(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, left + right); // Combine
    return 1 + max(left, right);                 // Return height to parent
}
```

## Traps
- **Leaf Node Check**: For root-to-leaf problems, check `!node->left && !node->right`, not just `!node`.
- **Pass-by-Value Paths**: Passing `vector<int> path` by value causes $O(N^2)$ memory copies; use pass-by-reference with `pop_back()`.
