# Monotonic Stack

## Signals
- Next / Previous Greater / Smaller Element (NGE, PGE, NSE, PSE) in $O(N)$ time.
- Boundary detection for histograms, container walls, or maximal rectangles.
- Subarray contribution (sum/count of subarray minimums or maximums).
- Lexicographical sequences with limited removals (Remove K Digits).

## Key Variations
- **Decreasing Stack** (top is smallest): Pop while `curr > st.top()`. Finds **Next Greater Element**.
- **Increasing Stack** (top is largest): Pop while `curr < st.top()`. Finds **Next Smaller Element**.
- **Circular Array**: Loop $2N$ times using `nums[i % n]`; only push indices when `i < n`.

## Code Skeleton
```cpp
// Next Greater Element (stores indices)
vector<int> res(n, -1);
stack<int> st;

for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[i] > nums[st.top()]) {
        res[st.top()] = nums[i];
        st.pop();
    }
    st.push(i);
}
```

## Traps
- **Store Indices, Not Values**: Indices provide both the value `nums[i]` and distance/width `i - st.top() - 1`.
- **Duplicate Handling**: In subarray contribution problems, use `<` on the left bound and `<=` on the right bound to avoid double-counting duplicate values.
- **Sentinel Flush**: In histogram problems, append a `0` height at the end to automatically flush remaining bars without extra cleanup loops.
