# Difference Array

## Signals
- Multiple range updates (add $val$ to range $[l, r]$) processed offline before querying final values.
- Replaces $O(N)$ update cost with $O(1)$ ($O(N + Q)$ total).
- Overlapping intervals, peak capacity checks (Car Pooling, Meeting Rooms II).

## Key Variations
- **1D Range Update**: `diff[l] += val`, `diff[r + 1] -= val`. Final values = running prefix sum of `diff`.
- **Coordinate Sweep-Line (`map<int, int>`)**: For sparse or large coordinates ($10^9$), record `+val` at start and `-val` at end.
- **2D Difference Array**: Add at top-left & bottom-right+1; subtract at top-right+1 & bottom-left+1.

## Code Skeleton
```cpp
vector<int> diff(n + 1, 0);

// Apply range updates
for (auto& op : updates) {
    int l = op[0], r = op[1], val = op[2];
    diff[l] += val;
    diff[r + 1] -= val;
}

// Reconstruct final array via prefix sum
for (int i = 1; i < n; i++) {
    diff[i] += diff[i - 1];
}
```

## Traps
- **Endpoints (Closed vs Half-Open)**:
  - Closed $[l, r]$: `diff[r + 1] -= val`.
  - Half-open $[l, r)$: `diff[r] -= val`.
- **Out of Bounds**: Size must be at least `n + 1` to safely access `diff[r + 1]`.
- **Offline Only**: Dynamic updates mixed with queries require a **Segment Tree with Lazy Propagation**.
