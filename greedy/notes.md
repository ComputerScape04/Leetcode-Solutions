# Greedy

## Signals
- Locally optimal choice guarantees a globally optimal solution.
- Reachability, jump games, or minimum step problems.
- Interval scheduling, task prioritization, or fuel / capacity conservation.

## Useful Observations
- **Single State Variable Replaces Path Storage**: In jump games, maintain only the maximum reachable index (`maxReach = max(maxReach, i + nums[i])`) instead of traversing or storing path history.
- **Sorting Criterion is the Solution Key**:
  - Maximize non-overlapping intervals: sort by **end time**.
  - Merge intervals / minimize partitions: sort by **start time**.
- **Exchange Argument Proof**: If swapping any optimal choice with your greedy choice never worsens the outcome, greedy is correct.
- **Two-Pass Technique**: When constraints apply from both left and right directions (e.g. Candy distribution), compute left-to-right pass then right-to-left pass.

## Key Variations
- **Farthest Reach**: Track `maxReach`; if `i > maxReach`, return unreachable (Jump Game I).
- **Level Boundary Expansion**: Count jumps when index reaches current level boundary (Jump Game II).
- **Earliest Deadline / End First**: Greedily select tasks or intervals that terminate earliest.
- **Two-Pass Greedy**: Enforce left neighbor condition, then enforce right neighbor condition (Candy).

## Code Skeleton
```cpp
// Jump Game I: Farthest reach
int maxReach = 0;
for (int i = 0; i < n; i++) {
    if (i > maxReach) return false;
    maxReach = max(maxReach, i + nums[i]);
}
return maxReach >= n - 1;
```

## Traps
- **Greedy Fallacy**: If decisions depend on future possibilities rather than past independent guarantees, greedy fails; switch to **Dynamic Programming**.
- **Wrong Sort Key**: Sorting intervals by start time instead of end time leads to suboptimal non-overlapping interval selection.
- **Negative Edge Cases**: Handling zero jumps or empty arrays without initial guards.
