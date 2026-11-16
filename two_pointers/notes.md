# Two Pointers

## Signals
- Array is sorted (or sortable in $O(N \log N)$).
- Finding pairs/triplets meeting a target sum or condition.
- In-place partitioning or modifying array with $O(1)$ extra space.
- Symmetric comparison from opposite ends (palindromes, area container).

## Key Variations
- **Opposite Ends (`left`, `right`)**: Move inward based on comparison (Two Sum II, Container With Most Water).
- **Fast & Slow**: Cycle detection (Floyd's algorithm) or linked list midpoint.
- **Read & Write (Same Direction)**: `read` scans elements, `write` collects valid ones in-place (Remove Duplicates, Move Zeroes).
- **Two Sequences**: Merging sorted arrays, subsequence checking.

## Code Skeleton
```cpp
// Opposite Ends (e.g., Two Sum II)
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return {left, right};
    else if (sum < target) left++;
    else right--;
}
```

## Traps
- **Skipping Duplicates**: In triplet/pair counting (e.g. 3Sum), advance past duplicate values: `while (left < right && nums[left] == nums[left + 1]) left++;`.
- **Loop Bounds**: Use `left < right` for distinct pair problems; use `left <= right` when the center element must be processed (e.g. binary search, palindromes).
