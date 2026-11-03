# Binary Search on Answer

### Recognition
- Asks for an extremum: "minimum maximum", "maximum minimum", "least speed / capacity / time to satisfy $X$".
- Input array does **not** need to be sorted.
- Answer lies in a bounded, continuous search space $[L, R]$.
- **Monotonic Feasibility**:
  - Minimizing: `[F, F, ..., T, T]` $\to$ if $X$ is valid, all values $> X$ are valid.
  - Maximizing: `[T, T, ..., F, F]` $\to$ if $X$ is valid, all values $< X$ are valid.
- Verifying feasibility (`isValid(mid)`) takes $O(N)$, yielding $O(N \log(\text{range}))$ total time.

### Common Patterns
- **Rate / Speed Minimization**: Minimum rate to finish work within $H$ hours (*Koko Eating Bananas*).
- **Capacity / Partition Minimization**: Min container capacity or max subarray sum across $k$ splits (*Capacity To Ship Packages*, *Split Array Largest Sum*).
- **Distance Maximization**: Place $k$ items to maximize the minimum distance (*Magnetic Force Between Two Balls*, *Aggressive Cows*).
- **Work / Time Minimization**: Minimum time for multiple workers to complete $T$ tasks (*Minimum Time to Complete Trips*).

### Core Steps
1. Define search range: `low = min_possible`, `high = max_possible`.
2. Implement `bool isValid(mid)` helper to test feasibility in $O(N)$.
3. Binary search loop:
   - While `low <= high`:
     - `mid = low + (high - low) / 2`.
     - **Minimizing**: if `isValid(mid)`, record `ans = mid`, search lower `high = mid - 1`; else `low = mid + 1`.
     - **Maximizing**: if `isValid(mid)`, record `ans = mid`, search higher `low = mid + 1`; else `high = mid - 1`.

### Key Traps
- **Boundary Selection**: Never set `low = 0` if `isValid` divides by `mid` (division by zero). Ensure `high` is large enough to contain the answer.
- **Integer Overflow**: Use `long long` for bounds and arithmetic.
- **Ceiling Division**: Use `(val + mid - 1) / mid` instead of floating-point `ceil((double)val / mid)` to avoid precision bugs.
