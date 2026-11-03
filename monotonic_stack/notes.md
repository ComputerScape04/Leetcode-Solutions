# Monotonic Stack

### Recognition
- Finding the **Next / Previous Greater / Smaller Element** (NGE / PGE / NSE / PSE) in $O(N)$ time.
- Boundary detection for histograms or rectangle areas (*Largest Rectangle in Histogram*).
- Subarray contribution problems (sum/count of subarray minimums or maximums).
- Constructing lexicographically optimal sequences with limited removals (*Remove K Digits*).
- Circular array wrap-around searches.

### Monotonicity Rules
- **Monotonically Increasing Stack** (bottom $\to$ top: small to large):
  - Pop when `curr < stack.top()`.
  - Finds **NSE** (Next Smaller Element) and **PSE** (Previous Smaller Element).
- **Monotonically Decreasing Stack** (bottom $\to$ top: large to small):
  - Pop when `curr > stack.top()`.
  - Finds **NGE** (Next Greater Element) and **PGE** (Previous Greater Element).

### Common Patterns
- **Next Greater Element**: Iterate array; while `nums[i] > nums[st.top()]`, pop and resolve NGE for `st.top()`.
- **Circular Array**: Iterate $2N$ steps using `nums[i % n]`; only push indices when `i < n`.
- **Histogram / Max Rectangle**: For each bar, height is `heights[mid]`, width is `i - st.top() - 1` after popping.
- **Subarray Contribution**: Number of subarrays where `nums[i]` is min = `(i - left_bound) * (right_bound - i)`.
- **Lexicographical Greedy**: Pop larger previous characters while remaining removal budget `k > 0`.

### Core Steps (NGE Template)
1. Initialize `vector<int> res(n, -1)` and `stack<int> st` (stores indices).
2. For `i` from `0` to `n - 1`:
   - While `!st.empty() && nums[i] > nums[st.top()]`:
     - `res[st.top()] = nums[i]`;
     - `st.pop()`;
   - `st.push(i)`.

### Key Traps
- **Store Indices, Not Values**: Indices provide both the value (`nums[i]`) and the distance/width (`i - st.top() - 1`).
- **Sentinel Elements**: Append a sentinel (e.g. `0` or $\pm\infty$) at index $n$ to flush all remaining elements without extra cleanup loops.
- **Double Counting with Duplicates**: In contribution problems, use strict inequality (`<`) on one side and non-strict (`<=`) on the other.
- **Integer Overflow**: Range product `(i - left) * (right - i) * val` can exceed 32-bit limits; cast to `long long`.
