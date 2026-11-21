# Binary Search on Answer

## Signals
- Extremum query: "minimum maximum", "maximum minimum", "least capacity/speed to satisfy condition".
- Input array does not need to be sorted.
- Feasibility function `isValid(mid)` is monotonic over a bounded domain $[low, high]$.

## Useful Observations
- **Monotonicity Unlocks Non-Sorted Arrays**: Even if the input array is completely unsorted, binary search applies if "can we achieve target $X$?" forms a monotonic $[T, T, ..., F, F]$ or $[F, F, ..., T, T]$ pattern.
- **Greedy Verification Function**: The predicate `bool isValid(mid)` can almost always be implemented with a simple greedy single-pass $O(N)$ algorithm.
- **Tight Search Bounds**: Set `low` to minimum possible valid answer (e.g. $1$ or $\max(nums)$) and `high` to worst-case theoretical answer (e.g. $\sum nums$ or $\max(nums) 	imes K$).
- **Integer Ceiling Trick**: Replace `ceil((double)a / b)` with `(a + b - 1) / b` to avoid slow floating-point math and precision bugs.

## Key Variations
- **Minimizing Answer (`[F, ..., F, T, ..., T]`)**: If `isValid(mid)` is true, mid is feasible; record candidate and explore smaller values (`high = mid - 1`).
- **Maximizing Answer (`[T, ..., T, F, ..., F]`)**: If `isValid(mid)` is true, mid is feasible; record candidate and explore larger values (`low = mid + 1`).

## Code Skeleton
```cpp
long long low = min_possible, high = max_possible, ans = -1;
while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (isValid(mid)) {
        ans = mid;
        high = mid - 1; // Or low = mid + 1 if maximizing
    } else {
        low = mid + 1;  // Or high = mid - 1 if maximizing
    }
}
return ans;
```

## Traps
- **Division by Zero**: Never set `low = 0` if `isValid(mid)` divides by `mid` (e.g., speed / rate problems).
- **32-Bit Overflow**: `low + high` or prefix accumulations inside `isValid(mid)` frequently exceed `INT_MAX`; always use `long long`.
- **Premature Floating Point Casts**: Floating-point operations lose precision on $10^9$ integers; keep checks in integer domain.
