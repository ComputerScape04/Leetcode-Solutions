# Difference Array

### Recognition
- Multiple range updates (add $val$ to range $[l, r]$) applied in batch before querying final values (offline processing).
- Replaces $O(N)$ per-update cost with $O(1)$ ($O(N + Q)$ total time).
- Interval overlap, peak load, or simultaneous capacity checks (*Car Pooling*, *Meeting Rooms II*).

### Common Patterns
- **1D Range Update**:
  - Update: `diff[l] += val`, `diff[r + 1] -= val`.
  - Reconstruct: Compute running prefix sum of `diff`.
- **Sparse / Coordinate Sweep-Line (`map<int, int>`)**:
  - For large coordinates ($10^9$) or sparse intervals, record deltas at boundary timestamps in an ordered map (*My Calendar III*).
- **2D Difference Array**:
  - Range $[r_1..r_2, c_1..c_2]$: `+val` at $(r_1, c_1)$ and $(r_2+1, c_2+1)$; `-val` at $(r_1, c_2+1)$ and $(r_2+1, c_1)$ (*Increment Submatrices by One*).

### Core Steps
1. Allocate `vector<int> diff(n + 1, 0)`.
2. For each update `[l, r, val]`:
   - `diff[l] += val`
   - `diff[r + 1] -= val`  *(or `diff[r] -= val` for half-open $[l, r)$)*
3. Reconstruct final array:
   - `nums[0] = diff[0]`
   - Loop `i` from `1` to `n - 1`: `nums[i] = nums[i - 1] + diff[i]`.

### Key Traps
- **Inclusive vs Exclusive Endpoints**:
  - Closed $[l, r]$: `diff[l] += val`, `diff[r + 1] -= val`.
  - Half-open $[start, end)$: `diff[start] += val`, `diff[end] -= val`.
- **Array Sizing**: Size must be at least `n + 1` (or `n + 2` for 1-indexing) to safely access `diff[r + 1]`.
- **Offline Only**: Dynamic queries interleaved with updates require a **Segment Tree with Lazy Propagation** or **Fenwick Tree**.
- **Negative Modulo in Cyclic Shifts**: Normalize string shift deltas via `((shift % 26) + 26) % 26`.
