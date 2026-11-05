# Intervals

### Recognition
- Input consists of ranges or pairs $[start, end]$.
- Merging overlapping ranges or inserting a range into a sorted list.
- Finding peak concurrent intervals (meeting rooms, server load).
- Minimizing removals to avoid overlap (interval scheduling).
- Finding intersections between two sets of intervals.

### Common Patterns
- **Merge Overlapping**:
  - Sort by start time. If `curr.start <= prev.end`, merge by updating `prev.end = max(prev.end, curr.end)` (*Merge Intervals*).
- **Insert Interval**:
  - Push intervals ending before `newInterval`. Merge overlapping intervals. Push remaining intervals (*Insert Interval*).
- **Non-Overlapping / Greedy Removal**:
  - Sort by **end time**. Greedily keep intervals finishing earliest to minimize removals (*Non-overlapping Intervals*).
- **Simultaneous Overlap (Meeting Rooms II)**:
  - Sort by start time. Maintain a **Min-Heap of end times**. If `heap.top() <= curr.start`, pop (reuse room), then push `curr.end`.
- **Interval Intersection**:
  - Two pointers: intersection is `[max(A.start, B.start), min(A.end, B.end)]`. Advance pointer with the earlier end time (*Interval List Intersections*).

### Core Steps (Merge Template)
1. Sort intervals by start time: `sort(intervals.begin(), intervals.end());`
2. Initialize `vector<vector<int>> res = {intervals[0]};`
3. For `i` from `1` to `n - 1`:
   - If `intervals[i][0] <= res.back()[1]`:
     - `res.back()[1] = max(res.back()[1], intervals[i][1]);`
   - Else:
     - `res.push_back(intervals[i]);`

### Key Traps
- **Sort Criterion**:
  - Sort by **start time** for merging, intersections, and room allocations.
  - Sort by **end time** when greedily picking maximum non-overlapping intervals.
- **Full Containment**: In `[1, 8]` and `[2, 4]`, merged end must use `max(8, 4) = 8`. Forgetting `max()` overwrites with the smaller end.
- **Boundary Condition**: Check whether touch points count as overlap ($[1, 2]$ and $[2, 3]$): `curr.start <= prev.end` (inclusive) vs `curr.start < prev.end` (exclusive).
