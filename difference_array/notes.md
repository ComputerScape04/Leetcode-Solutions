# Difference Array

## Signals
- Multiple range updates (add $val$ to range $[l, r]$) followed by final state evaluation.
- Replaces $O(N)$ interval modification cost with $O(1)$ operations ($O(N + Q)$ total).
- Overlapping intervals, peak resource capacity checks (Car Pooling, Meeting Rooms II).

## Useful Observations
- **Range Updates in $O(1)$**: An update of $+v$ on $[l, r]$ translates to two point modifications: `diff[l] += v` and `diff[r + 1] -= v`.
- **Reconstruction via Running Prefix Sum**: Taking the running prefix sum of the difference array restores the updated array in one linear pass.
- **Coordinate Sweep-Line via `std::map`**: For sparse or massive coordinates ($0 \dots 10^9$), use an ordered map to record updates only at boundary events in $O(Q \log Q)$ time.
- **Peak Resource Tracking**: Finding maximum simultaneous capacity needed corresponds to tracking the running maximum during the sweep-line reconstruction.

## Key Variations
- **1D Range Update**: Fixed size array with `diff[l] += val` and `diff[r + 1] -= val`.
- **Sparse Coordinate Sweep-Line**: `map<int, int> events; events[start] += val; events[end] -= val;`.
- **2D Difference Array**: Sub-matrix range addition using 4 corner operations.

## Code Skeleton
```cpp
vector<int> diff(n + 1, 0);

// Apply range updates
for (const auto& op : updates) {
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
- **Closed vs Half-Open Bounds**:
  - Closed $[l, r]$: decrement at `diff[r + 1]`.
  - Half-open $[l, r)$: decrement at `diff[r]`.
- **Out of Bounds Access**: The difference array must be sized to at least $n + 1$ to safely modify index $r + 1$.
- **Offline Only**: Difference arrays cannot answer intermixed queries and updates dynamically; use a **Segment Tree / Fenwick Tree** if queries are interleaved.
