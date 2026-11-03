# Monotonic Queue

### Recognition
- Finding the maximum or minimum in all sliding windows of size $k$ in $O(N)$ time.
- Optimizing 1D dynamic programming transitions constrained by a window: $\text{dp}[i] = \min_{i-k \le j < i}(\text{dp}[j]) + \text{cost}[i]$.
- Shortest subarray with sum at least $k$ (using prefix sums).

### Queue Monotonicity
- **Window Maximum (Decreasing Deque)**:
  - Front element is always the maximum in current window.
  - Maintain descending order: pop back while `nums[dq.back()] <= nums[i]`.
- **Window Minimum (Increasing Deque)**:
  - Front element is always the minimum in current window.
  - Maintain ascending order: pop back while `nums[dq.back()] >= nums[i]`.

### Core Steps (Sliding Window Maximum)
1. Initialize `deque<int> dq` (stores indices).
2. Iterate `i` from `0` to `n - 1`:
   - **Evict expired elements**: while `!dq.empty() && dq.front() <= i - k`, `dq.pop_front()`.
   - **Maintain monotonicity**: while `!dq.empty() && nums[dq.back()] <= nums[i]`, `dq.pop_back()`.
   - **Insert current index**: `dq.push_back(i)`.
   - **Record answer**: once `i >= k - 1`, current window max is `nums[dq.front()]`.

### Key Traps
- **Store Indices**: Store indices in `deque`, not values, so you can easily check if elements are outside the current window (`dq.front() <= i - k`).
- **Two Pop Directions**:
  - Pop from **front** to discard indices out of range ($< i - k + 1$).
  - Pop from **back** to discard elements violating monotonicity.
- **Monotonic Queue vs Priority Queue**: Monotonic queue runs in $O(N)$ overall ($O(1)$ amortized per item), whereas `priority_queue` takes $O(N \log k)$ and cannot selectively prune stale elements without lazy deletion.
