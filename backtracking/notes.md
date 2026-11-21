# Backtracking

## Signals
- Find all combinations, permutations, or subsets.
- Partitioning problems (e.g., Palindrome Partitioning).
- Explicit search spaces requiring state restoration (e.g., Word Search).
- Small constraints: $N \le 16$ ($O(2^N)$ or $O(N!)$).

## Useful Observations
- **`startIndex` vs Loop from 0**: Use `startIndex` when combinations/subsets do not care about element order; loop from 0 with a `used` tracker when order matters (permutations).
- **Sort First for Instant Duplicate Pruning**: Sort the array upfront, then skip duplicates using `if (i > startIndex && nums[i] == nums[i-1]) continue;`.
- **Reference Passing with Symmetric Push/Pop**: Pass `path` by reference; push before recursing and pop immediately after to maintain $O(N)$ space instead of $O(N^2)$ copies.
- **Early Feasibility Pruning**: If numbers are sorted and `currSum + nums[i] > target`, break immediately instead of making useless recursive calls.

## Key Variations
- **Subsets / Combinations (Order doesn't matter)**: Pass `startIndex`. Use `i + 1` for single-use items, or `i` for unlimited reuse.
- **Permutations (Order matters)**: Loop from `0` each call; track visited elements with `vector<bool> used` or in-place swap.
- **Partitioning**: Recurse on valid prefix slices (e.g., palindrome substrings) and advance start index.

## Code Skeleton
```cpp
void backtrack(int startIndex, int currSum, vector<int>& nums, int target, vector<int>& path, vector<vector<int>>& res) {
    if (currSum == target) {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; i < nums.size(); i++) {
        if (i > startIndex && nums[i] == nums[i-1]) continue; // Skip duplicates
        if (currSum + nums[i] > target) break;                // Early pruning

        path.push_back(nums[i]);
        backtrack(i + 1, currSum + nums[i], nums, target, path, res);
        path.pop_back(); // Backtrack
    }
}
```

## Traps
- **Missing State Restoration**: Every state modification (e.g., `path.push_back`, `grid[r][c] = '#'`) must be undone after recursion.
- **Skipping Duplicates Without Sorting**: Duplicate skips only work when identical elements are adjacent.
- **Pass-by-Value State Vectors**: Passing `vector<int> path` by value creates huge memory overhead; always pass by reference.
- **Missing `return` in Base Case**: Forgetting `return` after collecting a solution explores invalid deeper branches.
