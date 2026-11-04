# Heap / Priority Queue

### Recognition
- Finding the $k$-th smallest / largest element in a static collection or dynamic stream.
- Repeatedly querying and extracting minimums or maximums in $O(\log N)$ time.
- Merging $k$ sorted lists, sequences, or intervals.
- Greedy simulations where next best choice depends on dynamic states (e.g., CPU scheduling, room allocations).
- Tracking running medians or percentiles in a data stream (two-heap pattern).

### Common Patterns
- **Top $K$ Largest Elements**:
  - Maintain a **Min-Heap of size $k$**. Push elements and pop when size $> k$. Root holds the $k$-th largest (*Kth Largest Element in an Array*, *Top K Frequent Elements*).
- **Top $K$ Smallest Elements**:
  - Maintain a **Max-Heap of size $k$**. Pop when size $> k$. Root holds the $k$-th smallest.
- **Two Heaps (Running Median)**:
  - Max-Heap for smaller half, Min-Heap for larger half. Keep sizes balanced within 1 (*Find Median from Data Stream*).
- **Merge $K$ Sorted Streams**:
  - Push first element of each list into a Min-Heap `{val, list_index}`. Pop minimum, then push next element from that list (*Merge k Sorted Lists*).
- **Interval & Room Allocation**:
  - Sort intervals by start time; use a Min-Heap of end times to recycle freed rooms (*Meeting Rooms II*).

### Syntax & Comparators
- **Max-Heap (Default)**: `priority_queue<int> maxHeap;`
- **Min-Heap**: `priority_queue<int, vector<int>, greater<int>> minHeap;`
- **Custom Comparator Rule**:
  - If `comp(a, b)` returns `true`, **`a` has lower priority than `b`** (`b` rises to top).
  ```cpp
  struct Compare {
      bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
          return a.second > b.second; // Min-heap based on second element
      }
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
  ```

### Key Traps
- **Top $K$ Inversion Rule**: Finding $k$ **largest** elements requires a **Min-Heap** of size $k$ (so the smallest of the top $k$ can be evicted).
- **Heap is NOT Sorted**: Only `top()` is guaranteed to be the extremum; elements underneath are partially ordered (`heap[k-1]` has no meaning).
- **`pop()` Returns `void`**: Must call `top()` before `pop()` to capture the value.
- **Empty Guard**: Calling `top()` or `pop()` on an empty heap causes undefined behavior; always verify `!pq.empty()`.
- **$O(N)$ Build-Heap**: Initializing via `priority_queue<int> pq(nums.begin(), nums.end())` takes $O(N)$ using Floyd's build-heap, whereas inserting elements one by one takes $O(N \log N)$.
