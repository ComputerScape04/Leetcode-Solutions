# Hash Map / Hash Set

## Signals
- Fast $O(1)$ lookup, frequency counting, or membership tests.
- Finding complements (`target - x`) in a single pass.
- Grouping elements by an invariant key (e.g. sorted string for anagrams).
- Detecting duplicates or tracking visited states.

## Key Variations
- **Complement Lookup**: Look up `target - nums[i]` while iterating (Two Sum).
- **Frequency Map & Bucketing**: Count occurrences; bucket by frequency for top-k frequent.
- **Canonical Key Grouping**: Sort string or serialize state to group anagrams / equivalent configurations.
- **Streak Boundary (Set)**: Put elements into `unordered_set`. Only start a streak from `x` if `x - 1` is not in set (Longest Consecutive Sequence).

## Code Skeleton
```cpp
// Complement Lookup (Two Sum)
unordered_map<int, int> seen; // val -> index
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[nums[i]] = i;
}
```

## Traps
- **Default Insertion via `[]`**: Accessing `mp[key]` silently inserts `key` with default value 0 and expands map size. Use `mp.count(key)` or `mp.find(key)` for checks.
- **No Hash for Pairs**: `std::unordered_map` cannot hash `std::pair` or `std::vector` out of the box; serialize to string or use `std::map`.
- **Memory Overhead**: Hash maps have node pointer overhead. For small alphabets (e.g. lowercase letters), prefer a fixed array `int freq[26] = {0}`.
