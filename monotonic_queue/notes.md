# Monotonic Queue

## Signals
- Finding min/max in all sliding windows of size $k$ in $O(N)$ time.
- Optimizing 1D DP transitions over a window: $dp[i] = \min_{i-k \le j < i}(dp[j]) + cost[i]$.
- Shortest subarray with sum at least $k$.

## Key Variations
- **Decreasing Deque (Window Max)**: Front is maximum. Pop back while `nums[dq.back()] <= nums[i]`.
- **Increasing Deque (Window Min)**: Front is minimum. Pop back while `nums[dq.back()] >= nums[i]`.

## Code Skeleton
```cpp
// Sliding Window Maximum
deque<int> dq; // Stores indices
vector<int> res;

for (int i = 0; i < n; i++) {
    // 1. Evict out-of-window elements
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

    // 2. Maintain monotonic decreasing order
    while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

    dq.push_back(i);

    // 3. Record answer once window size reaches k
    if (i >= k - 1) res.push_back(nums[dq.front()]);
}
```

## Traps
- **Store Indices**: Store indices in `deque`, not raw values, to check expiry `dq.front() <= i - k`.
- **Two Pop Directions**:
  - `pop_front()`: removes stale expired elements out of range.
  - `pop_back()`: removes elements that violate monotonicity.
- **Monotonic Queue vs Priority Queue**: Monotonic queue is $O(N)$ total ($O(1)$ amortized per element) vs $O(N \log k)$ for heap.
