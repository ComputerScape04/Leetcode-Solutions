# Monotonic Queue

## Signals
- Finding min/max in all sliding windows of size $k$ in $O(N)$ time.
- Optimizing 1D DP transitions: $dp[i] = \min_{i-k \le j < i}(dp[j]) + cost[i]$.
- Shortest subarray with sum at least $k$.

## Useful Observations
- **Store Indices, Not Values**: Always store indices in the `std::deque`; indices allow validating both value comparisons (`nums[dq.back()] <= nums[i]`) and window expiry (`dq.front() <= i - k`).
- **Two Distinct Pop Directions**:
  - `pop_front()`: Evicts expired elements that moved outside the active sliding window.
  - `pop_back()`: Evicts dominated elements that are worse candidates than the incoming item.
- **Amortized $O(1)$ per Element**: Each element is pushed and popped at most once, providing $O(N)$ overall time compared to $O(N \log K)$ for a priority queue.
- **Monotonicity Direction**:
  - Finding **Maximum**: Maintain a monotonically decreasing deque (largest at `front`).
  - Finding **Minimum**: Maintain a monotonically increasing deque (smallest at `front`).

## Key Variations
- **Sliding Window Maximum**: Decreasing deque holding indices; answer recorded once index $\ge k - 1$.
- **Windowed DP Optimization**: Maintain deque of best DP states within step window $[i-k, i-1]$.
- **Shortest Subarray with Sum $\ge K$**: Monotonic queue over prefix sum array.

## Code Skeleton
```cpp
// Sliding Window Maximum
deque<int> dq; // Stores indices
vector<int> res;

for (int i = 0; i < n; i++) {
    // 1. Evict out-of-window elements from front
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

    // 2. Maintain monotonic decreasing order from back
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

    dq.push_back(i);

    // 3. Record result once window size reaches k
    if (i >= k - 1) res.push_back(nums[dq.front()]);
}
```

## Traps
- **Pushing Values instead of Indices**: Pushing raw values makes it impossible to check if the element has expired from the sliding window.
- **Evicting from the Wrong End**: Expired elements must be popped from `front`; monotonic violations must be popped from `back`.
- **Off-By-One Expiry Check**: An element at index `j` is outside a window of size $k$ ending at $i$ when $j \le i - k$.
