# Prefix Sum

## Signals
- Subarray sum queries in $O(1)$ time after $O(N)$ precomputation.
- Subarray sum equals $k$ or is divisible by $k$.
- Array contains **negative numbers** (disqualifying sliding window).

## Key Variations
- **Static Range Query**: `sum(l, r) = pref[r + 1] - pref[l]` using 1-indexed prefix array.
- **Prefix Sum + Hash Map**: Count subarrays summing to $k$ by checking if `currSum - k` exists in map.
- **Prefix Modulo (Divisibility)**: If `currSum % k` repeats, the subarray between the two indices is divisible by $k$.
- **2D Prefix Sum**: `pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]`.

## Code Skeleton
```cpp
// Subarray Sum Equals K
unordered_map<long long, int> freq;
freq[0] = 1; // Base case: empty prefix
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
- **Missing Base Case**: Forgetting `freq[0] = 1` fails to count valid subarrays starting at index 0.
- **Negative Modulo in C++**: `(-5) % 3 == -2`. Normalize remainder using `((sum % k) + k) % k`.
- **Integer Overflow**: Running sum often exceeds 32-bit `int`; use `long long`.
- **Static Only**: Updates take $O(N)$. For frequent updates with range queries, use a **Fenwick Tree / Segment Tree**.
