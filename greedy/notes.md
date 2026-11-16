# Greedy

## Signals
- Making locally optimal choices guarantees global optimality.
- Reachability, jump games, or minimum step problems.
- Task scheduling, interval picking, or priority-based placement.

## Key Variations
- **Farthest Reach (Jump Game)**: Track `maxReach = max(maxReach, i + nums[i])`. If `i > maxReach`, unreachable.
- **Minimum Jumps (BFS-like Greedy)**: Jump when reaching current boundary; extend boundary to farthest reachable point.
- **Frequency First (Task Scheduler)**: Schedule highest frequency elements first using a max-heap and cooldown queue.
- **Two-Pass / Sort Criterion (Queue Reconstruction)**: Sort by primary feature (e.g. height descending), then insert by secondary count.

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
- **Greedy Fallacy**: Always check if a greedy choice can lead to a dead end; if past choices affect future subproblems differently, use **Dynamic Programming**.
- **Incorrect Sort Key**: Picking intervals greedily requires sorting by **end time**, not start time.
