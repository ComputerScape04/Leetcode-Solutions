# Monotonic Stack

## Signals
- Next / Previous Greater or Smaller Element (NGE, PGE, NSE, PSE) in $O(N)$ time.
- Boundary detection for histograms, container walls, or maximal rectangles.
- Subarray contribution calculations (sum of subarray minimums or maximums).
- Lexicographical sequence construction with limited removal budget.

## Useful Observations
- **Store Indices for Value and Width**: Storing indices in the stack gives both the boundary value `nums[st.top()]` and the span width `i - st.top() - 1` simultaneously.
- **Sentinel Flush Technique**: In histogram and rectangle problems, append a sentinel height `0` to the input array; this automatically empties the stack at the end without extra cleanup loops.
- **Strict vs Non-Strict Equality for Duplicates**: In subarray contribution problems (e.g. Sum of Subarray Minimums), use `<` for the left bound and `\le` for the right bound to avoid double-counting duplicate values.
- **Stack Monotonicity Meaning**:
  - Monotonically **increasing** stack (bottom to top): finds Previous / Next **Smaller** Element.
  - Monotonically **decreasing** stack (bottom to top): finds Previous / Next **Greater** Element.

## Key Variations
- **Next Greater Element**: Decreasing stack; elements pop when `nums[i] > nums[st.top()]`.
- **Largest Rectangle in Histogram**: Increasing stack; compute area whenever an element is popped.
- **Circular Array Search**: Loop $2N$ times using modulo indexing `nums[i % n]`; only push indices when $i < n$.
- **Remove K Digits**: Maintain increasing stack; greedily pop larger previous digits while budget $k > 0$.

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
- **Empty Stack Check**: Always check `!st.empty()` before calling `st.top()` or `st.pop()`.
- **Width Calculation when Stack is Empty**: When computing width after popping, if the stack becomes empty, the popped element was the minimum so far, so width spans the entire prefix `i`.
- **Double Counting Duplicates**: In contribution counting, using non-strict comparison on both sides counts equal elements twice.
