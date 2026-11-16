# Binary Search on Answer

## Signals
- Extremum question: "minimum maximum", "maximum minimum", "least capacity/speed to satisfy $X$".
- Input array does **not** need to be sorted.
- Answer lies in a bounded range $[low, high]$ with monotonic feasibility (`isValid(mid)`).

## Key Variations
- **Minimizing Answer (`[F, ..., F, T, ..., T]`)**: If `isValid(mid)`, record answer and try smaller: `high = mid - 1`; else `low = mid + 1`.
- **Maximizing Answer (`[T, ..., T, F, ..., F]`)**: If `isValid(mid)`, record answer and try larger: `low = mid + 1`; else `high = mid - 1`.

## Code Skeleton
```cpp
long long low = min_val, high = max_val, ans = -1;
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
- **Division by Zero**: Never set `low = 0` if `isValid(mid)` divides by `mid` (e.g. speed problems).
- **Integer Ceiling**: Use integer ceiling formula `(val + mid - 1) / mid` instead of floating-point `ceil((double)val / mid)`.
- **Overflow**: Use `long long` for `low`, `high`, and `mid` calculations.
