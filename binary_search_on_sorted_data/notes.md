# Binary Search on Sorted Data

## Signals
- Array is sorted, rotated, or has a monotonic predicate (`[F, ..., F, T, ..., T]`).
- Demands $O(\log N)$ search time.
- Target is an exact value, boundary/insertion index, or peak.

## Key Variations
- **Exact Match**: `nums[mid] == target`.
- **Lower Bound (First $\ge target$)**: If `nums[mid] >= target`, search left (`high = mid - 1`), record candidate; else search right (`low = mid + 1`).
- **Rotated Array**: One half (`[low..mid]` or `[mid..high]`) is always strictly sorted. Determine which half is sorted, then check if target falls inside it.
- **Peak Finding**: If `nums[mid] < nums[mid + 1]`, peak is to the right (`low = mid + 1`); else left (`high = mid`).

## Code Skeleton
```cpp
int low = 0, high = n - 1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return -1; // Or return `low` for insertion position
```

## Traps
- **Integer Overflow**: Always use `low + (high - low) / 2` instead of `(low + high) / 2`.
- **Bound Mismatches**: Pair `while (low <= high)` with `high = mid - 1` and `low = mid + 1`.
- **Rotated Array Duplicates**: When `nums[low] == nums[mid] == nums[high]`, increment `low++` and decrement `high--` to break ties.
