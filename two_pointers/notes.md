# Two Pointers

## Signals
- Array is sorted (or sortable in $O(N \log N)$).
- Finding pairs or triplets meeting a target sum or constraint.
- In-place array partitioning or modification with $O(1)$ extra space.
- Symmetric comparison from opposite ends (palindromes, container area).

## Useful Observations
- **Opposite Ends for Sorted Pairs**: Moving pointers inward based on `sum < target` (`left++`) or `sum > target` (`right--`) reduces $O(N^2)$ pair searches to $O(N)$ without hash map memory overhead.
- **Fast and Slow for In-Place Modification**: Use a `fast` pointer to scan all elements and a `slow` pointer to write valid elements in-place (`nums[slow++] = nums[fast]`).
- **Advance Past Sibling Duplicates**: In 3Sum or pair counting, skip duplicate values using `while (left < right && nums[left] == nums[left + 1]) left++;` to prevent duplicate output triplets.
- **Greedy Inward Step in Container Area**: In Container With Most Water, always advance the pointer pointing to the shorter bar; moving the taller bar can never increase the area.

## Key Variations
- **Opposite Ends (`left`, `right`)**: Two Sum II, Container With Most Water.
- **Fast & Slow**: In-place removal (Remove Duplicates, Move Zeroes).
- **Fixed Pointer + Two Pointers**: 3Sum (outer loop fixes $i$, two pointers solve remaining 2Sum).
- **Two Sequences**: Merging sorted arrays or checking subsequences.

## Code Skeleton
```cpp
// Opposite Ends (Two Sum II)
int left = 0, right = n - 1;
while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) return {left + 1, right + 1};
    else if (sum < target) left++;
    else right--;
}
```

## Traps
- **Skipping Duplicates**: In 3Sum, remember to skip duplicates for *both* the outer fixed pointer and the inner two pointers.
- **Loop Bounds**: Use `left < right` for distinct pair problems; use `left <= right` when the center element must be examined (e.g. binary search, palindromes).
- **Unsorted Input**: Two pointers from opposite ends strictly requires a sorted sequence.
