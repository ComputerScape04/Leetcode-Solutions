# Binary Search Tree (BST)

## Signals
- Sorted tree queries, range searches, or predecessor/successor lookups.
- Validating binary search tree structure.
- Finding Lowest Common Ancestor (LCA) in BST.

## Useful Observations
- **Inorder Traversal is Strictly Sorted**: An inorder traversal (`Left -> Root -> Right`) of a valid BST always yields values in strictly increasing order.
- **Range Propagation for $O(N)$ Validation**: Validate a BST in top-down fashion by passing valid allowable range `(low, high)` down to subtrees; left child gets `(low, val)`, right child gets `(val, high)`.
- **$O(H)$ LCA without Traversal Overhead**: If both search targets are smaller than current node, branch left; if both are greater, branch right; otherwise, current node is the LCA split point.
- **Pointer Comparison Prevents Inorder Vector Allocation**: Instead of saving the full inorder traversal into a vector, keep a single `TreeNode* prev` pointer to check `prev->val >= curr->val` on the fly in $O(1)$ extra space.

## Key Variations
- **Validate BST**: Check valid ranges recursively with `long long` limits or track `prev` node in an inorder traversal.
- **K-th Smallest Element**: Perform inorder traversal and decrement $k$ at each visited node; stop when $k = 0$.
- **LCA in BST**: Use value comparisons to decide whether to walk left, right, or return root.

## Code Skeleton
```cpp
// Validate BST using Range Bounds
bool isValidBST(TreeNode* root, long long low = LLONG_MIN, long long high = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= low || root->val >= high) return false;
    return isValidBST(root->left, low, root->val) &&
           isValidBST(root->right, root->val, high);
}
```

## Traps
- **Local vs Global Invariant**: Checking only `root->left->val < root->val` is insufficient; all nodes in the left subtree must be smaller than the root.
- **Integer Limits Overflow**: BST node values can equal `INT_MIN` or `INT_MAX`; initialize bounds using `LLONG_MIN` and `LLONG_MAX` or node pointers.
- **Strict Inequalities**: BST definition does not allow duplicate values (`<=` or `>=` violates the BST property).
