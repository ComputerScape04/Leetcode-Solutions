# Sliding Window

## Signals
- Contiguous subarrays or substrings meeting a condition.
- Target is finding minimum/maximum length, or counting valid windows.
- Elements are non-negative or window condition changes monotonically.

## Useful Observations
- **Monotonic Property Prerequisite**: Sliding window is only applicable when expanding the right boundary monotonically increases (or maintains) the state, and shrinking the left boundary monotonically decreases it.
- **Shrink Condition Rule of Thumb**:
  - Finding **Maximum Length**: Expand `right`; shrink `left` while the window is **invalid**.
  - Finding **Minimum Length**: Expand `right`; shrink `left` while the window is **valid** (recording candidates before shrinking).
- **Exact Count via Difference of At-Most**: Problems asking for subarrays with "exactly $K$ distinct elements" are easily solved using `atMost(K) - atMost(K - 1)`.
- **Fixed vs Variable Window**: For fixed size $K$, advance `right`, and only begin advancing `left` once `right >= K - 1`.

## Key Variations
- **Fixed Size $K$**: Maintain running state, add incoming right, remove outgoing left once width reaches $k$.
- **Variable Window (Longest)**: Expand right; shrink while invalid; update `ans = max(ans, right - left + 1)`.
- **Variable Window (Shortest)**: Expand right; while valid, update `ans = min(ans, right - left + 1)` and shrink left.
- **At Most K Trick**: Count valid subarrays ending at `right` as `right - left + 1`.

## Code Skeleton
```cpp
// Variable Window (Max Length)
int left = 0, ans = 0;
for (int right = 0; right < n; right++) {
    // 1. Add nums[right] to window state
    while (/* window is invalid */) {
        // 2. Remove nums[left] from window state
        left++;
    }
    ans = max(ans, right - left + 1);
}
```

## Traps
- **Window Size Calculation**: The window length is always `right - left + 1`, not `right - left`.
- **Negative Numbers**: Negative values break monotonic expansion/shrink logic; switch to **Prefix Sum + Hash Map**.
- **Inverted Shrink Logic**: Shrinking when valid vs invalid depends strictly on whether you want the longest or shortest window.
