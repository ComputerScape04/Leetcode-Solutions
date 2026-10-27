When to look for a Binary Search approach:
- The input array is sorted (or partially sorted / rotated).
- The search space has a monotonic property: `condition(x)` is `[false, false, ..., true, true]` or vice-versa.
- Time limit demands $O(\log n)$ runtime instead of $O(n)$.
- The problem asks for the "minimum maximum", "maximum minimum", or "least value that satisfies a condition" (binary search on answer).
- You need to find boundary elements (first occurrence, last occurrence, peak element, or rotation pivot).

Common problem types:
- Classic search:
  - Find target index or insertion position (e.g., Binary Search, Search Insert Position).
- Rotated / modified sorted arrays:
  - Find inflection points or search target across pivot (e.g., Search in Rotated Sorted Array, Find Minimum in Rotated Sorted Array).
- Peak finding:
  - Use slope comparisons `nums[mid] < nums[mid + 1]` (e.g., Find Peak Element).
- Binary search on answer space:
  - Range is `[min_possible, max_possible]`, use a helper `isValid(mid)` (e.g., Koko Eating Bananas, Capacity To Ship Packages).
- 2D matrices:
  - Row/col monotonic properties (e.g., Search a 2D Matrix, Search a 2D Matrix II).

Core Template:
1. Identify search range: `low = min_val`, `high = max_val`.
2. Compute midpoint safely: `mid = low + (high - low) / 2`.
3. Check condition and discard half the search space:
   - If `isValid(mid)`, move one boundary (`high = mid` or `high = mid - 1`).
   - Else, move the opposite boundary (`low = mid + 1`).
4. Terminate when `low > high` (or `low == high` depending on boundary rules).

Key Traps:
- Integer overflow: avoid `(low + high) / 2`; use `low + (high - low) / 2`.
- Infinite loops: ensure `low` or `high` changes each step when using `while (low < high)`.
- Off-by-one errors: match your loop condition (`low <= high` vs `low < high`) to your boundary updates (`mid ± 1` vs `mid`).
