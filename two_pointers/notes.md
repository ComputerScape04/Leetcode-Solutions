# Two Pointers

### Recognition
- Input is sorted (or sortable in $O(N \log N)$).
- Finding pairs, triplets, or subarrays meeting a target sum or condition.
- Modifying arrays in-place ($O(1)$ auxiliary space).
- Comparing elements from opposite ends or traversing two sequences simultaneously.
- Cycle detection or finding midpoints in linked lists.

### Common Patterns
- **Opposite Ends (`left`, `right` inward)**:
  - Target sum pairs and triplets (*Two Sum II*, *3Sum*).
  - Palindrome validation and string reversals (*Valid Palindrome*).
  - Greedy area/boundary elimination (*Container With Most Water*, *Trapping Rain Water*).
- **Fast & Slow**:
  - Cycle detection and entry point (*Floyd's Tortoise and Hare*).
  - Linked list midpoint (`slow` 1 step, `fast` 2 steps).
- **Read & Write (same direction, conditional pace)**:
  - In-place element removal and deduplication (*Remove Duplicates*, *Move Zeroes*).
  - Three-way partitioning (*Sort Colors* / Dutch National Flag).
- **Two Sequences**:
  - Merging sorted collections (*Merge Sorted Array*).
  - Subsequence checking (*Is Subsequence*).

### Core Steps
- **Opposite Ends**:
  1. Set `left = 0`, `right = n - 1`.
  2. While `left < right`: evaluate `sum = nums[left] + nums[right]`.
  3. If `sum == target`: record/return; if `sum < target`: `left++`; else: `right--`.
- **Read & Write**:
  1. Set `write = 0`.
  2. Loop `read` from `0` to `n - 1`: if `nums[read]` matches condition, set `nums[write++] = nums[read]`.

### Key Traps
- **Duplicate Skipping**: Skip identical elements (`while (left < right && nums[left] == nums[left + 1]) left++`) to avoid duplicate pairs/triplets.
- **Loop Boundary**: Use `left < right` for distinct pairs; use `left <= right` when the center element must be processed.
