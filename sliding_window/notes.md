# Sliding Window

## Signals
- Contiguous sequence problem (subarray or substring).
- Finding minimum, maximum, or exact count matching a condition.
- Monotonic state: expanding `right` monotonically grows or accumulates the tracked metric.

## Key Variations
- **Fixed Size ($k$)**: Slide window by adding `nums[right]` and removing `nums[right - k]`.
- **Variable Size (Find Longest)**: Expand `right`. While invalid, shrink `left++`. Update answer: `right - left + 1`.
- **Variable Size (Find Shortest)**: Expand `right`. While valid, update answer, then shrink `left++` to minimize.

## Code Skeleton
```cpp
// Variable Window (Max length)
int left = 0, ans = 0;
for (int right = 0; right < n; right++) {
    // 1. Add nums[right] to state
    while (/* window is invalid */) {
        // 2. Remove nums[left] from state
        left++;
    }
    ans = max(ans, right - left + 1);
}
```

## Traps
- **Window Size Formula**: Always `right - left + 1`, not `right - left`.
- **Negative Numbers**: Negative values break monotonic expansion/shrink logic; use **Prefix Sum + Hash Map** instead.
- **Shrink Condition Inversion**:
  - Finding *maximum* window $\to$ shrink while **invalid**.
  - Finding *minimum* window $\to$ shrink while **valid**.
