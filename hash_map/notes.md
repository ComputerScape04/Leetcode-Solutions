When to look for a Hash Map / Hash Set approach:
- You need $O(1)$ average time lookups, insertions, or deletions.
- Finding pairs, complements, or frequencies (e.g., target sum complements `target - x`).
- Tracking seen elements or finding duplicates/intersections.
- Grouping elements by an invariant key (e.g., sorted string, canonical representation).
- Mapping relationships (e.g., character isomorphic mapping, clone graph node mapping).
- Fast prefix state lookups (prefix sum with hash map to count subarrays equaling $k$).

Common problem types:
- Complement lookup:
  - Check if `target - nums[i]` exists in map while iterating (e.g., Two Sum).
- Frequency counting / Bucketing:
  - Count occurrences of characters or numbers; sort by frequency (e.g., Top K Frequent Elements, Valid Anagram).
- Grouping by signature:
  - Canonical key serves as map bucket (e.g., Group Anagrams using sorted string or char count as key).
- Prefix sum + Hash map:
  - Store frequency of prefix sums to find subarrays summing to $k$ in $O(N)$ (e.g., Subarray Sum Equals K).
- Set operations / Consecutive sequences:
  - Insert elements into `unordered_set`, then check `set.count(x - 1)` to find sequence starts (e.g., Longest Consecutive Sequence).

Core Templates:

1. Complement Lookup (Two Sum):
```cpp
unordered_map<int, int> seen; // val -> index
for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (seen.count(complement)) {
        return {seen[complement], i};
    }
    seen[nums[i]] = i;
}
```

2. Grouping by Canonical Key (Group Anagrams):
```cpp
unordered_map<string, vector<string>> groups;
for (const string& s : strs) {
    string key = s;
    sort(key.begin(), key.end());
    groups[key].push_back(s);
}
```

3. Prefix Sum Tracking (Subarray Sums):
```cpp
unordered_map<long long, int> prefixCounts;
prefixCounts[0] = 1; // base case: sum of empty prefix
long long currSum = 0, count = 0;
for (int num : nums) {
    currSum += num;
    if (prefixCounts.count(currSum - target)) {
        count += prefixCounts[currSum - target];
    }
    prefixCounts[currSum]++;
}
```

Key Traps:
- `operator[]` inserts a default-initialized value: calling `mp[key]` modifies map size if key is missing. Use `mp.count(key)` or `mp.find(key)` to inspect without inserting.
- Missing custom hash: `std::unordered_map` cannot hash compound keys (`std::pair`, `std::vector`) without a custom hash struct. Use `std::map` or string serialization instead.
- Worst-case time complexity: hash collisions degrade operations to $O(N)$. For competitive programming / anti-hash tests, reserve capacity or use custom hash seeds.
- Memory overhead: hash maps carry high node overhead; for dense integer keys in a small range (e.g. lowercase letters), prefer a fixed-size array `int freq[26] = {0}`.
