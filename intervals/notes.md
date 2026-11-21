# Intervals

## Signals
- Input consists of ranges $[start, end]$.
- Merging overlapping intervals or inserting into an already sorted list.
- Calculating concurrent overlaps (meeting rooms, resource allocation).
- Maximizing non-overlapping intervals (interval scheduling).

## Useful Observations
- **Sorting Criterion Dictates the Solution**:
  - Merging overlapping intervals: sort by **start time**.
  - Maximizing non-overlapping intervals (min removals): sort by **end time**.
- **Containment Trap (`max` is Mandatory)**: When merging intervals like `[1, 8]` and `[2, 4]`, always update `prev.end = max(prev.end, curr.end)` to avoid truncating containment.
- **Min-Heap for Room Allocation (Meeting Rooms II)**: Sort intervals by start time; store end times in a Min-Heap. If `minHeap.top() <= curr.start`, pop and reuse that room; otherwise push a new room.
- **Touch Overlap Sensitivity**: Always confirm whether touching endpoints count as overlap ($[1, 2]$ and $[2, 3]$ overlap $\iff$ `curr.start <= prev.end`).

## Key Variations
- **Merge Overlapping**: Sort by start time; extend `merged.back()[1] = max(..., curr[1])`.
- **Insert Interval**: Add all intervals strictly before, merge overlapping with `newInterval`, then append remaining.
- **Min Removals for Non-Overlapping**: Sort by end time; keep the one ending earliest.
- **Meeting Rooms II**: Sort by start time; maintain a Min-Heap of active finish times.

## Code Skeleton
```cpp
// Merge Overlapping Intervals
sort(intervals.begin(), intervals.end());
vector<vector<int>> merged = {intervals[0]};

for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] <= merged.back()[1]) {
        merged.back()[1] = max(merged.back()[1], intervals[i][1]);
    } else {
        merged.push_back(intervals[i]);
    }
}
```

## Traps
- **Forgetting `max()` on End Update**: Directly assigning `prev.end = curr.end` breaks when a larger interval completely contains a smaller subsequent interval.
- **Inclusive vs Exclusive Endpoints**: Pay close attention to whether intervals are $[start, end]$ (closed) or $[start, end)$ (half-open).
- **Missing Sort**: Never assume the input intervals are already sorted unless explicitly stated.
