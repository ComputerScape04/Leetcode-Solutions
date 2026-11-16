# Intervals

## Signals
- Input is a list of ranges $[start, end]$.
- Merging overlapping intervals or inserting into a sorted list.
- Finding concurrent overlaps (meeting rooms, resource allocation).
- Maximizing non-overlapping intervals (interval scheduling).

## Key Variations
- **Merge Overlapping**: Sort by **start**. If `curr.start <= prev.end`, merge: `prev.end = max(prev.end, curr.end)`.
- **Insert Interval**: Add all before, merge overlapping with `newInterval`, then add all after.
- **Max Non-Overlapping (Min Removals)**: Sort by **end time**. Greedily pick intervals that end earliest.
- **Meeting Rooms II**: Sort by **start**. Maintain a Min-Heap of end times; reuse room if `heap.top() <= curr.start`.

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
- **Sorting Criterion**:
  - Sort by **start time** for merging and room allocations.
  - Sort by **end time** for greedy interval scheduling (max non-overlapping).
- **Containment Trap**: For `[1, 8]` and `[2, 4]`, always use `max(prev.end, curr.end) = 8`. Forgetting `max` overwrites `8` with `4`.
- **Touch Overlap**: Check problem definition: does $[1, 2]$ and $[2, 3]$ overlap? Use `<=` if yes, `<` if no.
