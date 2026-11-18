# Backtracking Notes

## Signals
- Find all combinations, permutations, or subsets.
- Explicit constraints (prune invalid paths early).
- Grid search where visited cells must be restored (e.g., Word Search).
- Partitioning problems (e.g., Palindrome Partitioning).
- Small input constraints: $N \le 16$ ($O(2^N)$ or $O(N!)$ complexity).

## Key Variations
- **Subsets / Combinations (Order doesn't matter)**: Pass `startIndex`. Use `i + 1` to use each item once, or `i` to reuse items.
- **Permutations (Order matters)**: Loop from `0` every call; track used elements with `vector<bool> used` or in-place `swap`.
- **Duplicate Handling**: Sort `nums` first. Skip duplicates with `if (i > startIndex && nums[i] == nums[i-1]) continue;`.

## Generic Code Skeleton
```cpp
void backtrack(State& state) {
    // 1. Base Case: valid solution found
    if (is_solution(state)) {
        record_solution(state);
        return; // stop branch if no further extensions needed
    }

    // 2. Iterate through all possible choices at current step
    for (const auto& choice : get_candidates(state)) {
        // Prune invalid choices
        if (!is_valid(choice, state)) 
            continue;

        // A. Make choice
        apply(choice, state);

        // B. Recurse to next step
        backtrack(state);

        // C. Undo choice (Backtrack)
        revert(choice, state);
    }
}
```

## Traps
- **Missing State Restoration**: Every modification (e.g. `path.push_back`, `grid[r][c] = '#'`) must be undone after recursion returns.
- **Duplicate Branching**: Skipping duplicates without sorting `nums` first will not catch identical adjacent values.
- **Pass-by-Value Paths**: Passing `vector<int> path` by value creates $O(N)$ copies at every frame; use `vector<int>& path`.
- **Missing `return` in Base Case**: Omitting `return` after recording a solution leads to invalid child branches.
