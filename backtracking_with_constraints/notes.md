# Backtracking with Constraints

## Signals
- Combinations with unique sum targets and duplicate elements (Combination Sum II).
- Exact grid placement with row/column/diagonal conflict rules (N-Queens, Sudoku).
- State-space search with strict bounding functions.

## Useful Observations
- **Branch Pruning via Sorting**: Sorting candidates descending allows quick rejection of subtrees that overshoot constraints.
- **$O(1)$ Conflict Checks via Bitmasks / Hash Arrays**: Use boolean flags or bitmasks for rows, columns, and diagonals (`diag1 = r - c + n`, `diag2 = r + c`) instead of scanning lines in $O(N)$.
- **Single Solution Early Return**: When only one valid configuration is needed (e.g., Sudoku Solver), have the DFS function return `bool` and exit immediately once `true` is found.
- **Duplicate Suppression at Sibling Level**: Skip `if (i > startIndex && candidates[i] == candidates[i-1]) continue;` to allow duplicate values across tree depth while preventing duplicate branches at the same tree level.

## Key Variations
- **Bounded Sum with Duplicates**: Use each element at most once; sort upfront to prune branches overshooting target.
- **Grid Constraint Propagation**: Sudoku and N-Queens; place a choice, update row/column/box bitmasks, recurse, and clear bitmasks on backtrack.
- **Word Search / Grid Maze**: Mark cell as visited in-place using a sentinel character (`'#'`), explore 4 directions, and restore character on return.

## Code Skeleton
```cpp
// Combination Sum II Pattern
void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Prune duplicate siblings
        if (candidates[i] > target) break;                            // Sorted array early exit

        path.push_back(candidates[i]);
        backtrack(i + 1, target - candidates[i], candidates, path, res);
        path.pop_back();
    }
}
```

## Traps
- **Level vs Depth Duplicates**: Using `i > 0` instead of `i > start` blocks valid identical elements along the recursive path (e.g. `[1, 1, 2]`).
- **Bitmask Overflow**: When using bitmasks for constraints with size $\ge 32$, use `long long` or `std::bitset`.
- **Incomplete Grid Reset**: Failing to restore grid characters after all 4 recursive directions fails subsequent branch traversals.
