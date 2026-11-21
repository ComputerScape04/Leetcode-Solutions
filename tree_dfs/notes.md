# Tree DFS

## Signals
- Root-to-leaf paths, path sums, or path collection.
- Tree depth, height, or diameter calculations.
- Subtree validation (BST property, symmetry, isomorphism).
- Ancestor or descendant relationships in tree structures.

## Useful Observations
- **Adjacency List over Matrix**: Represent trees with directed edges `adj[parent].push_back(child)` to use $O(N)$ memory and avoid $N \times N$ matrix MLE ($O(N^2)$ space).
- **Directed Edges Drop Visited Array**: In rooted trees moving parent $\to$ child, directed edges eliminate the need for a `visited` array or parent checks.
- **State Array for Ancestor Queries**: For small alphabets (size $\Sigma \le 26$), maintain a fixed-size `last_seen[26]` array during DFS to lookup closest ancestors in $O(1)$ time.
- **Pass-by-Value vs In-Place Backtracking**: Passing a small state (like `array<int, 26>`) by value automatically preserves ancestor state on the call stack; for large structures, pass by reference and undo changes upon return.
- **Postorder for Subtree Aggregations**: Compute child subtree results first, then aggregate at parent (`size[u] = 1 + sum(size[children])`).

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
- **Pass-by-Value Paths**: Passing `vector<int> path` or `string s` by value causes $O(N^2)$ memory copies; use pass-by-reference with `pop_back()`.
- **Unbounded Tree Recursion**: Extremely skewed trees ($N = 10^5$) can cause stack overflow; ensure recursion depth matches memory limits.
