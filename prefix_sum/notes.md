# Prefix Sum

## Signals
- Subarray sum queries in $O(1)$ time after $O(N)$ precomputation.
- Subarray sum equals $k$ or is divisible by $k$.
- Array contains **negative numbers** (which invalidates sliding window).

## Useful Observations
- **Prefix Sum + Hash Map Solves Negative Numbers**: Sliding window fails with negative numbers because expanding does not guarantee monotonically increasing sums; prefix sum with a frequency hash map works in $O(N)$ regardless of signs.
- **Base Case `freq[0] = 1`**: Always initialize the prefix frequency map with `freq[0] = 1` to account for valid subarrays that start at index 0.
- **Prefix Modulo for Divisibility**: If `pref[j] % k == pref[i] % k`, the subarray sum `pref[j] - pref[i]` is divisible by $k$.
- **C++ Modulo Normalization**: Negative numbers produce negative remainders in C++ (`-5 % 3 == -2`); normalize remainders via `((sum % k) + k) % k`.

## Key Variations
- **1D Range Sum**: `sum(l, r) = pref[r + 1] - pref[l]` using a 1-indexed prefix array.
- **Prefix Sum + Hash Map**: Count subarrays summing to $k$ by querying count of `currSum - k`.
- **Prefix Modulo**: Subarray sums divisible by $k$.
- **2D Prefix Sum**: Sub-matrix sums using inclusion-exclusion.

## Code Skeleton
```cpp
// Subarray Sum Equals K
unordered_map<long long, int> freq;
freq[0] = 1; // Base case: accounts for subarrays starting at index 0
long long currSum = 0, count = 0;

for (int x : nums) {
    currSum += x;
    if (freq.count(currSum - k)) {
        count += freq[currSum - k];
    }
    freq[currSum]++;
}
```

## Traps
- **Omitting `freq[0] = 1`**: Forgetting the base case skips any valid subarray that begins at index 0.
- **Negative Remainders**: Unnormalized remainders fail equality checks against positive remainders.
- **Integer Overflow**: Prefix sums often exceed `INT_MAX`; always use `long long` for running accumulations.
- **Static Only**: Standard prefix sum requires $O(N)$ to rebuild after updates; use a **Fenwick Tree / Segment Tree** for dynamic point updates.
