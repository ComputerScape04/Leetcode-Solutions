# Binary Search Tree (BST) Notes

## Core Properties
1. **Inorder Traversal**: An inorder traversal (`Left -> Root -> Right`) of a BST yields strictly increasing values.
2. **Subtree Invariant**: Every node in the left subtree must be `< root->val`; every node in the right subtree must be `> root->val`.

---

## LeetCode 98: Validate Binary Search Tree

### Approaches
1. **Range Propagation (Optimal)**
   - Pass valid bounds `(low, high)` down to subtrees.
   - Left child range: `(low, node->val)`.
   - Right child range: `(node->val, high)`.
   - Time: $O(N)$, Space: $O(H)$ recursion stack.
   - Early exits on first violation.

2. **Inorder with Previous Pointer**
   - Track `prev` node pointer during traversal.
   - Fail if `prev != nullptr && node->val <= prev->val`.
   - Time: $O(N)$, Space: $O(H)$.

3. **Inorder to Vector (Suboptimal)**
   - Collect all elements into `vector<int>` and check if sorted.
   - Time: $O(N)$, Space: $O(N)$ extra memory.
   - Cannot exit early.

### Critical Edge Cases
- **Integer overflow**: Node values can equal `INT_MAX` or `INT_MIN`. Use `long long` bounds (`LLONG_MIN`, `LLONG_MAX`) or `TreeNode*` boundary pointers.
- **Duplicates**: BST definition requires strictly less/greater (`<=` or `>=` is invalid).
- **Empty / Single Node**: Empty tree is valid; single node tree is valid.
