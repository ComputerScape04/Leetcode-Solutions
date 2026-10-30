When to look for a Prefix Sum approach:
- You need repeated sum or aggregation queries over contiguous subarrays or submatrices in $O(1)$ time after $O(N)$ or $O(N \times M)$ precomputation.
- You need to count or find subarrays satisfying a specific sum condition (e.g., sum equals $k$, sum divisible by $k$).
- Negative numbers are present in the array (standard two-pointer / sliding window breaks because window expansion is not monotonic).
- You need to perform multiple range addition or update operations $[L, R]$ efficiently (using a difference array).
- You need to find pivot or equilibrium indices where the sum to the left equals the sum to the right.

Common problem types & patterns:
- Static Range Sum Queries (1D):
  - Precompute a prefix sum array to answer `sumRange(left, right)` in $O(1)$ time (e.g., Range Sum Query - Immutable).
- Prefix Sum + Hash Map (Target Subarray Sum):
  - Count subarrays summing to $k$: track frequency of prefix sums. For current prefix sum $S$, check if $S - k$ exists in the map (e.g., Subarray Sum Equals K).
  - Longest subarray summing to $k$: store the earliest index of each prefix sum to maximize `i - map[currSum - k]` (e.g., Maximum Size Subarray Sum Equals k).
- Prefix Sum with Modulo (Divisibility):
  - Subarrays with sum divisible by $k$: track prefix sums modulo $k$. If `currSum % k` was seen before, the subarray between them is divisible by $k$ (e.g., Subarray Sums Divisible by K, Continuous Subarray Sum).
- State Transformation (Equal 0s and 1s):
  - Replace 0s with -1s, turning the problem into finding subarrays summing to 0 (e.g., Contiguous Array).
- Difference Array (Range Updates):
  - Increment elements in $[l, r]$ by $val$ in $O(1)$ using `diff[l] += val` and `diff[r + 1] -= val`, then reconstruct the final array using a running prefix sum (e.g., Corporate Flight Bookings, Car Pooling).
- 2D Prefix Sum (Grid Submatrix Queries):
  - Query any rectangular region $(r_1, c_1)$ to $(r_2, c_2)$ in $O(1)$ using the 2D inclusion-exclusion principle (e.g., Range Sum Query 2D - Immutable).

Core Templates:

1. 1D Prefix Sum (1-Indexed for Safe Bounds):
```cpp
vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
}

// Query sum in range [left, right] (0-indexed inclusive):
long long rangeSum = prefix[right + 1] - prefix[left];
```

2. Prefix Sum + Hash Map (Count Subarrays Summing to K):
```cpp
unordered_map<long long, int> prefixCounts;
prefixCounts[0] = 1; // Base case: prefix sum 0 occurs once before array starts
long long currSum = 0;
int count = 0;

for (int num : nums) {
    currSum += num;
    if (prefixCounts.count(currSum - k)) {
        count += prefixCounts[currSum - k];
    }
    prefixCounts[currSum]++;
}
return count;
```

3. Difference Array (Range Updates):
```cpp
vector<int> diff(n + 1, 0);

// Apply update: add 'val' to all elements in range [l, r]
diff[l] += val;
diff[r + 1] -= val;

// Reconstruct original array via prefix sum
vector<int> result(n);
int runningSum = 0;
for (int i = 0; i < n; ++i) {
    runningSum += diff[i];
    result[i] = runningSum;
}
```

4. 2D Prefix Sum (Inclusion-Exclusion Principle):
```cpp
// Build 2D prefix sum table of size (m + 1) x (n + 1)
vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        pref[i + 1][j + 1] = matrix[i][j] 
                            + pref[i][j + 1] 
                            + pref[i + 1][j] 
                            - pref[i][j];
    }
}

// Query submatrix sum from (r1, c1) to (r2, c2) inclusive
int subgridSum = pref[r2 + 1][c2 + 1] 
               - pref[r1][c2 + 1] 
               - pref[r2 + 1][c1] 
               + pref[r1][c1];
```

Key Traps:
- Base case `prefixCounts[0] = 1`: forgetting to initialize the hash map with `0` having count 1 (or index -1 for length) will miss valid subarrays that start at index 0.
- Negative numbers with modulo: in C++, `(-5) % 3 == -2`. When working with modular arithmetic, normalize negative remainders using `((currSum % k) + k) % k`.
- Integer overflow: running sums can easily exceed 32-bit signed limits (`INT_MAX`); use `long long` for prefix tables, accumulators, and map keys.
- Off-by-one errors: prefer 1-indexed prefix arrays of size $N + 1$ with `prefix[0] = 0` to eliminate special branches for `left == 0`.
- Sliding Window vs Prefix Sum: sliding window requires monotonic window behavior (typically all non-negative numbers). When negative numbers exist, switch to prefix sums + hash maps.
- Static vs Dynamic data: prefix sums provide $O(1)$ queries but take $O(N)$ time to update when an element changes. If elements are frequently modified alongside range queries, use a Binary Indexed Tree (Fenwick Tree) or Segment Tree instead.
