When to look for a Monotonic Stack approach:
- You need to find the **Next Greater Element (NGE)**, **Next Smaller Element (NSE)**, **Previous Greater Element (PGE)**, or **Previous Smaller Element (PSE)** for each element in an array in $O(N)$ time instead of naive $O(N^2)$.
- The problem asks for the nearest element to the left or right that is strictly or non-strictly greater/smaller than the current element.
- You need to find the maximum rectangular area under a histogram or in a 2D binary matrix.
- You need to calculate the contribution of each element as a minimum or maximum across all contiguous subarrays (e.g., Sum of Subarray Minimums / Ranges).
- You are constructing a lexicographically smallest or largest number/sequence by removing or picking $k$ elements while maintaining relative order.
- The problem involves circular arrays where searching for the next greater/smaller element wraps around to index 0.

Common problem types & patterns:
- Next Greater / Next Smaller Element:
  - Find the first larger or smaller element to the right or left (e.g., Next Greater Element I, Daily Temperatures).
- Circular Array Traversal:
  - Simulate a circular array by looping $2N$ times and indexing with `i % n` (e.g., Next Greater Element II).
- Online Spans / Previous Greater Element:
  - Maintain a stack of pairs `(price, span)` to aggregate consecutive days with prices $\le$ today (e.g., Online Stock Span).
- Largest Rectangle / Histogram:
  - For each bar, find its left boundary (PSE) and right boundary (NSE). The area is `heights[i] * (right - left - 1)` (e.g., Largest Rectangle in Histogram, Maximal Rectangle).
- Subarray Contribution (Min / Max of Subarrays):
  - Count subarrays where `nums[i]` is the extremum: `(i - left_bound) * (right_bound - i) * nums[i]`. Use strict inequality on one side and non-strict on the other to prevent double-counting duplicates (e.g., Sum of Subarray Minimums, Sum of Subarray Ranges).
- Greedy Lexicographical Construction:
  - Build the best sequence greedily by popping larger prior elements from the stack when a smaller element is seen, provided enough future elements remain (e.g., Remove K Digits, Remove Duplicate Letters, Smallest Subsequence of Distinct Characters).
- Trapped Water (Horizontal Bars):
  - Use a decreasing stack where the current element acts as a right wall, the top of the stack is the bottom of the pit, and the next stack element is the left wall (e.g., Trapping Rain Water).

Core Templates:

1. Next Greater Element (Store Indices, Left-to-Right):
```cpp
vector<int> nextGreaterElements(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // Monotonically decreasing stack of indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            int prevIdx = st.top();
            st.pop();
            result[prevIdx] = nums[i]; // nums[i] is the NGE for nums[prevIdx]
        }
        st.push(i);
    }
    return result;
}
```

2. Next Greater Element in Circular Array:
```cpp
vector<int> nextGreaterElementsCircular(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores indices

    // Loop twice across the array to handle wrap-around
    for (int i = 0; i < 2 * n; ++i) {
        int currIdx = i % n;
        while (!st.empty() && nums[currIdx] > nums[st.top()]) {
            result[st.top()] = nums[currIdx];
            st.pop();
        }
        if (i < n) {
            st.push(currIdx);
        }
    }
    return result;
}
```

3. Largest Rectangle in Histogram (Sentinel Boundary):
```cpp
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st; // Monotonically increasing stack of indices
    int maxArea = 0;

    // Append 0 as a sentinel height at index n to flush all remaining elements
    for (int i = 0; i <= n; ++i) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

4. Subarray Contribution (Sum of Subarray Minimums - No Double Counting):
```cpp
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    long long totalSum = 0;
    int MOD = 1e9 + 7;
    stack<int> st; // Monotonically increasing stack of indices

    for (int i = 0; i <= n; ++i) {
        // Use 0 as sentinel for elements >= 1 at index n
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
            int mid = st.top();
            st.pop();
            
            // Previous smaller element index: st.top() if not empty, else -1
            long long left = st.empty() ? -1 : st.top();
            long long right = i; // Next smaller or equal element index
            
            long long count = (mid - left) * (right - mid) % MOD;
            totalSum = (totalSum + count * arr[mid]) % MOD;
        }
        st.push(i);
    }
    return totalSum;
}
```

5. Greedy Lexicographical Reduction (Remove K Digits):
```cpp
string removeKdigits(string num, int k) {
    string st = ""; // Use string directly as a stack

    for (char digit : num) {
        while (!st.empty() && k > 0 && st.back() > digit) {
            st.pop_back();
            k--;
        }
        if (!st.empty() || digit != '0') { // Avoid leading zeros
            st.push_back(digit);
        }
    }

    // If k > 0 remaining, truncate from the back
    while (!st.empty() && k > 0) {
        st.pop_back();
        k--;
    }

    return st.empty() ? "0" : st;
}
```

Key Traps:
- Store indices, not values: storing indices allows you to retrieve the value via `nums[st.top()]` AND calculate span/widths via `(curr_index - st.top() - 1)`. Storing values alone loses distance information.
- Duplicate values & double counting: in subarray contribution problems (e.g. Sum of Subarray Minimums), using non-strict inequality on both sides (`<=` on left and right) counts identical subarrays multiple times. Use strict (`<`) on one side and non-strict (`<=`) on the other.
- Unprocessed elements (sentinels): elements remaining in the stack after the loop need to be flushed. Adding a dummy sentinel value (e.g., `0` for non-negative histogram heights, `-infinity` / `infinity`) at index $N$ ensures the stack flushes cleanly inside the loop.
- Monotonicity direction mix-up:
  - **Monotonically Increasing Stack** (bottom $\to$ top): elements increase; popping occurs when encountering a smaller element. Finds **Next Smaller Element** (NSE) and **Previous Smaller Element** (PSE).
  - **Monotonically Decreasing Stack** (bottom $\to$ top): elements decrease; popping occurs when encountering a larger element. Finds **Next Greater Element** (NGE) and **Previous Greater Element** (PGE).
- Empty stack check before `top()`: always check `!st.empty()` before calling `st.top()` or `st.pop()`.
- Integer overflow: multiplying ranges `(i - left) * (right - i) * val` can easily exceed 32-bit signed integer limits ($2 \times 10^9$); always cast intermediate products to `long long` and apply modulo arithmetic where required.
