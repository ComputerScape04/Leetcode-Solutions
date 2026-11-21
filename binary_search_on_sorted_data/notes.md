# Binary Search on Sorted Data

## Signals
- Array is sorted, rotated, or follows a step predicate.
- Demands $O(\log N)$ lookup or insertion index.
- Finding exact target, lower/upper bounds, or local peaks.

## Useful Observations
- **Half-Sorted Invariant in Rotated Arrays**: In any rotated sorted array, splitting at `mid` always leaves at least one half strictly sorted (`nums[low] <= nums[mid]` or `nums[mid] <= nums[high]`).
- **Peak Finding via Local Slope**: Binary search does not require a fully sorted array; comparing `nums[mid]` to `nums[mid + 1]` determines which side must contain a peak.
- **Standardized Invariant (`while (low <= high)`)**: Pairing `low <= high` with `low = mid + 1` and `high = mid - 1` prevents infinite loops and leaves `low` at the correct insertion index upon termination.

## Key Variations
- **Exact Match**: Standard `nums[mid] == target`.
- **Lower Bound (First $\ge target$)**: If `nums[mid] >= target`, record candidate, search left (`high = mid - 1`); else search right (`low = mid + 1`).
- **Rotated Array Search**: Check which side is sorted, check if target lies within that range, and prune the other half.
- **Handling Duplicates**: When `nums[low] == nums[mid] == nums[high]`, increment `low++` and decrement `high--` to shrink the ambiguous search space.

## Code Skeleton
```cpp
int low = 0, high = n - 1;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) low = mid + 1;
    else high = mid - 1;
}
return -1; // Or return `low` for insertion position (std::lower_bound equivalent)
```

## Traps
- **Integer Overflow**: Always calculate mid as `low + (high - low) / 2` instead of `(low + high) / 2`.
- **Strict vs Non-Strict Inequalities**: In rotated array search with duplicates, `<` vs `<=` dictates whether you can guarantee sortedness.
- **Off-By-One Bounds**: Mixing `while (low < high)` with `high = mid - 1` can miss the boundary element.
