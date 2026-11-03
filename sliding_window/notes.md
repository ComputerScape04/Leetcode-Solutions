# Sliding Window

### Recognition
- Contiguous sequence problem (subarray, substring).
- Optimization goal (max/min sum, longest/shortest length, target count).
- Monotonic property: expanding window only increases (or maintains) the tracked metric.

### Window Types
- **Fixed-Size ($k$)**:
  - Build initial window of size $k$.
  - Slide by adding `nums[right]` and removing `nums[right - k]`.
- **Variable-Size**:
  - Expand `right` to include elements and update state.
  - Shrink `left` with `while (condition violated)` (or to minimize window).

### Core Steps
1. Initialize `left = 0`, state tracking (sum, frequency map), `ans`.
2. Iterate `right` from `0` to `n - 1`:
   - Add `nums[right]` to current window state.
   - While window is invalid (or while valid, if minimizing):
     - Remove `nums[left]` from state.
     - Increment `left++`.
   - Update `ans` using window length `right - left + 1`.

### Key Traps
- **Window Length Formula**: Always `right - left + 1`.
- **Monotonicity Breakdown**: Negative numbers break standard sliding window; use **Prefix Sum + Hash Map** instead.
- **Shrink Condition**: Distinguish between *finding maximum window* (shrink while invalid) and *finding minimum window* (shrink while valid).
