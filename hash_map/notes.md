# Hash Map / Hash Set

### Recognition
- Need $O(1)$ average time lookups, insertions, or deletions.
- Finding complements (`target - x`), pairs, or tracking frequencies.
- Grouping elements sharing an invariant signature (e.g., sorted string).
- Detecting duplicates or tracking visited states/cycles.
- Counting subarrays meeting target criteria (combined with prefix sums).

### Common Patterns
- **Complement Lookup**:
  - Check if `target - nums[i]` exists in map during a single pass (*Two Sum*).
- **Frequency Counting & Bucketing**:
  - Track counts via `unordered_map<T, int>`; bucket or sort by frequency (*Top K Frequent Elements*, *Valid Anagram*).
- **Grouping by Canonical Key**:
  - Normalize elements into a key (e.g., sorted string, character count tuple) and group in `unordered_map<Key, vector<T>>` (*Group Anagrams*).
- **Prefix Sum + Hash Map**:
  - Store prefix sum frequencies to count subarrays summing to $k$ in $O(N)$ (*Subarray Sum Equals K*).
- **Sequence Boundary in Set**:
  - Insert all numbers into `unordered_set`. Only start counting consecutive streak from `x` if `x - 1` is NOT in set (*Longest Consecutive Sequence*).

### Core Steps (Prefix Sum + Hash Map)
1. Initialize `map[0] = 1` (base case: empty prefix sum).
2. Maintain running `currSum += x`:
   - If `(currSum - target)` exists in map: add `map[currSum - target]` to `count`.
   - Increment `map[currSum]++`.

### Key Traps
- **Default Insertion with `[]`**: Accessing `mp[key]` inserts a default value and increases map size if missing. Use `mp.count(key)` or `mp.find(key)` for read-only checks.
- **Missing Custom Hasher**: `std::unordered_map` cannot hash `std::pair` or `std::vector` without a custom hash struct; use `std::map` or serialize to string instead.
- **Memory Overhead**: Hash maps carry significant node overhead. For small/fixed alphabets (e.g., lowercase letters), prefer a flat array (`int freq[26] = {0}`).
