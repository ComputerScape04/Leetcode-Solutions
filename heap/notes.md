# Heap / Priority Queue

## Signals
- Finding the $k$-th smallest / largest element in a stream or array.
- Continuous dynamic min/max queries in $O(\log N)$ time.
- Merging $k$ sorted lists or scheduling intervals.
- Tracking running medians in real time.

## Key Variations
- **Top $K$ Largest Elements**: Use a **Min-Heap of size $k$**. Pop when size $> k$; top holds the $k$-th largest.
- **Top $K$ Smallest Elements**: Use a **Max-Heap of size $k$**. Pop when size $> k$; top holds the $k$-th smallest.
- **Two Heaps (Median)**: Max-Heap for smaller half, Min-Heap for larger half. Keep sizes balanced $\le 1$.
- **Merge $K$ Sorted Streams**: Min-Heap holding `{val, list_index}`. Pop minimum, advance that list.

## Code Skeleton
```cpp
// Min-Heap of size K (Finds K-th Largest)
priority_queue<int, vector<int>, greater<int>> minHeap;

for (int x : nums) {
    minHeap.push(x);
    if (minHeap.size() > k) {
        minHeap.pop(); // Evicts the smallest among top elements
    }
}
return minHeap.top(); // K-th largest
```

## Traps
- **Inversion Rule**: To find $k$ **largest**, use a **Min-Heap** (so smallest of the candidates is evicted).
- **`pop()` is `void`**: In C++, `pq.pop()` does not return the element. Call `pq.top()` first.
- **Empty Guard**: Calling `top()` or `pop()` on an empty heap causes undefined behavior.
- **$O(N)$ Build**: Constructing via `priority_queue<int> pq(nums.begin(), nums.end())` is $O(N)$, whereas pushing one-by-one is $O(N \log N)$.
