# Prefix Sum

### Recognition
- Subarray or submatrix sum queries in $O(1)$ time after $O(N)$ precomputation.
- Counting or finding subarrays meeting sum or divisibility conditions.
- Array contains **negative numbers** (disqualifying sliding window).
- Finding equilibrium/pivot indices where left sum equals right sum.

### Common Patterns
- **Static Range Queries**:
  - `sumRange(l, r) = pref[r + 1] - pref[l]` using a 1-indexed prefix array (*Range Sum Query*).
- **Prefix Sum + Hash Map**:
  - Count subarrays summing to $k$: check if `currSum - k` exists in map (*Subarray Sum Equals K*).
  - Longest subarray summing to $k$: store earliest index of `currSum` to maximize `i - map[currSum - k]`.
- **Prefix Modulo (Divisibility)**:
  - If `currSum % k` repeats, the subarray between the two indices is divisible by $k$ (*Subarray Sums Divisible by K*).
- **State Transformation (Equal Counts)**:
  - Replace 0s with -1s: finding equal 0s and 1s reduces to finding subarrays with sum 0 (*Contiguous Array*).
- **2D Prefix Sum (Inclusion-Exclusion)**:
  - Build: `pref[i][j] = val + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]`.
  - Query: `pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1]`.

### Core Steps
1. Build prefix array of size `n + 1` with `pref[0] = 0`.
2. Compute `pref[i + 1] = pref[i] + nums[i]`.
3. Range sum of `nums[left..right]` = `pref[right + 1] - pref[left]`.

### Key Traps
- **Base Case `map[0] = 1`**: Missing the empty prefix fails to detect valid subarrays starting at index 0.
- **Negative Modulo**: In C++, `(-5) % 3 == -2`. Normalize remainders using `((sum % k) + k) % k`.
- **Integer Overflow**: Running prefix sums often exceed 32-bit signed limits; use `long long`.
- **Static Restriction**: Range queries take $O(1)$, but updates take $O(N)$. For frequent element updates, use a **Fenwick / Segment Tree**.
