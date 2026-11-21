# Hash Map / Hash Set

## Signals
- Average $O(1)$ key lookup, existence check, or frequency counting.
- Finding complements (`target - x`) in a single pass.
- Grouping elements by invariant canonical signatures (e.g., anagrams).
- Tracking unique elements or visited states.

## Useful Observations
- **Complement Lookup Eliminates Nested Loops**: Look up `target - nums[i]` while iterating; avoids $O(N^2)$ brute-force pair searching.
- **Canonical Key Normalization**: Group equivalent items by sorting strings or serializing character count arrays into strings (`#1#0#2...`) as map keys.
- **Streak Boundary Check Eliminates Redundant Work**: In Longest Consecutive Sequence, only launch counting from $x$ if $x - 1$ is absent from the set; avoids $O(N^2)$ repeated walks and ensures $O(N)$ runtime.
- **Fixed Array over Hash Map for Small Alphabets**: For lowercase English letters (`a-z`), replace `unordered_map` with a fixed-size `vector<int> count(26)` or `int count[26]` for faster cache-friendly lookups without hashing overhead.

## Key Variations
- **Complement Lookup**: Two Sum and pair matching.
- **Frequency Map & Bucketing**: Top-K frequent elements using count maps and bucket arrays.
- **Signature Grouping**: Group Anagrams using sorted string keys.
- **Sequence Boundary Check**: Longest Consecutive Sequence using `unordered_set`.

## Code Skeleton
```cpp
// Two Sum Complement Lookup
unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[nums[i]] = i;
}
```

## Traps
- **Default Insertion via `[]`**: Accessing `mp[key]` automatically default-inserts `key` with value 0, inadvertently modifying map size; use `mp.count(key)` or `mp.find(key)`.
- **Unhashable Types**: `std::unordered_map` has no default hash function for `std::pair` or `std::vector`; use a custom hash, serialize to string, or use `std::map`.
- **Hash Collisions in Worst Case**: Adversarial inputs can cause $O(N)$ bucket collisions in `unordered_map`; reserve capacity with `mp.reserve()` if needed.
