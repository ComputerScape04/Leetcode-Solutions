# Heap / Priority Queue

## Signals
- Dynamically finding the $k$-th smallest or largest elements in a stream or array.
- Continuous min/max queries in $O(\log N)$ time.
- Merging $k$ sorted lists or scheduling overlapping intervals.
- Tracking running medians in real time.

## Useful Observations
- **Heap Inversion Rule**:
  - To find the $k$-th **largest** element, use a **Min-Heap of size $k$** (pops the smaller elements, leaving largest $k$ at bottom and $k$-th largest at top).
  - To find the $k$-th **smallest** element, use a **Max-Heap of size $k$**.
- **$O(N)$ Heapify vs $O(N \log N)$ Insert**: Building a heap all at once via range constructor `priority_queue<int> pq(nums.begin(), nums.end())` takes $O(N)$ time, whereas pushing elements one by one takes $O(N \log N)$.
- **Two Balanced Heaps for Running Median**: Maintain a Max-Heap for the smaller half and a Min-Heap for the larger half; balance sizes so difference is $\le 1$.
- **K-Way Merge via Min-Heap**: Push `{val, row, col}` of the first element of each list; pop min and insert its immediate successor to merge $K$ lists in $O(N \log K)$ time.

## Key Variations
- **K-th Largest Element**: Min-Heap of size $k$.
- **Two Heaps (Median)**: Max-Heap for lower half, Min-Heap for upper half.
- **K-Way Merge**: Min-Heap tracking active heads across $k$ sorted streams.
- **Custom Comparator**: Compare structs or pairs: `priority_queue<T, vector<T>, Compare>`.

## Code Skeleton
```cpp
// K-th Largest Element using Min-Heap of size K
priority_queue<int, vector<int>, greater<int>> minHeap;
for (int x : nums) {
    minHeap.push(x);
    if (minHeap.size() > k) {
        minHeap.pop(); // Evicts smallest among top candidates
    }
}
return minHeap.top(); // K-th largest
```

## Traps
- **`pop()` Return Type**: In C++, `pq.pop()` returns `void`; always inspect `pq.top()` before popping.
- **Calling `top()` on Empty Heap**: Accessing `top()` on an empty priority queue causes undefined behavior.
- **Custom Comparator Semantics**: `std::priority_queue` uses inverted comparator logic compared to `std::sort`; returning `a > b` builds a Min-Heap.
