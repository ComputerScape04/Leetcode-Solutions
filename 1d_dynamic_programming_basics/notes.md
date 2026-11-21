# 1D Dynamic Programming Basics

## Signals
- Problem asks for min/max cost, number of ways, or reachability.
- Decisions at step $i$ depend only on a fixed number of previous states (e.g., $i-1, i-2$).
- Overlapping subproblems with optimal substructure.

## Useful Observations
- **Rolling Variables Eliminate $O(N)$ Space**: If $dp[i]$ only depends on $dp[i-1]$ and $dp[i-2]$, replace the array with two variables (`prev1`, `prev2`) for $O(1)$ space.
- **Top-Down to Bottom-Up Translation**: Write the memoized recursion first; iteratively filling the table from base cases up avoids recursion stack limits.
- **Decision Branching (Take vs Skip)**: Represent problems like House Robber as `dp[i] = max(skip, take) = max(dp[i-1], nums[i] + dp[i-2])`.
- **Target as State Index**: In coin change or subset sum, use remaining amount as the array index: `dp[target]` aggregates sub-targets.

## Key Variations
- **Fibonacci Style**: Current state is the sum of previous two states (Climbing Stairs).
- **Decision State (Take or Leave)**: Rob or skip current house (House Robber).
- **Target Reachability / Min Steps**: Minimum coins or steps to reach target $S$ (Coin Change).
- **Longest Increasing Subsequence**: $O(N^2)$ simple DP vs $O(N \log N)$ using binary search with patience sorting.

## Code Skeleton
```cpp
// Space-Optimized 1D DP (e.g., Climbing Stairs / House Robber)
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int curr = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

## Traps
- **Incorrect Base Case Initialization**: Always verify base cases for $n = 0, 1$ before running the loop.
- **Unreachable States**: Initialize min-cost DP tables with a safe infinity (`1e9`), not `INT_MAX`, to prevent overflow on `dp[i - c] + 1`.
- **Out of Bounds Indexing**: Check that $i - 	ext{step} \ge 0$ before accessing earlier states.
