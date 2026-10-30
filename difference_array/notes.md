When to look for a Difference Array approach:
- You need to perform multiple range update operations (e.g., add $val$ to all elements in range $[l, r]$) on an array.
- All updates are applied in batch **before** querying the final array or prefix states (offline processing).
- A naive update would take $O(N)$ per operation ($O(Q \times N)$ total), but difference array reduces each update to $O(1)$ ($O(N + Q)$ total).
- Range overlapping / concurrent interval problems where you need the maximum overlapping count at any point (e.g., peak capacity, room allocations).
- Submatrix range additions where all increments happen before reading the final grid.

Common problem types & patterns:
- 1D Range Addition (Fixed Bounds):
  - Apply $k$ range additions $[l, r, val]$ starting with an array of zeros or existing values (e.g., Range Addition, Corporate Flight Bookings).
- Interval Overlap / Capacity Check:
  - Check whether simultaneous load never exceeds capacity by treating trips as $[start, end)$ range additions (e.g., Car Pooling, Meeting Rooms II).
- String Range Shifts:
  - Apply cyclic forward/backward shifts to substrings across multiple operations (e.g., Shifting Letters II).
- Coordinate / Sparse Difference Array (Sweep-Line with Map):
  - When coordinates are large (up to $10^9$) or sparse, use `map<int, int>` instead of a fixed-size vector to record changes at critical boundary points (e.g., My Calendar III, Describe the Painting).
- 2D Difference Array (Subgrid Updates):
  - Add $val$ to entire submatrices $(r_1, c_1)$ to $(r_2, c_2)$ in $O(1)$ time, then reconstruct the grid using 2D prefix sums (e.g., Increment Submatrices by One).

Core Templates:

1. 1D Difference Array (Fixed Bounds $[l, r]$ Inclusive):
```cpp
// Size n + 1 to prevent out-of-bounds access when r = n - 1
vector<int> diff(n + 1, 0);

// Apply update: add 'val' to range [l, r] (0-indexed, inclusive)
void update(int l, int r, int val, vector<int>& diff) {
    diff[l] += val;
    diff[r + 1] -= val;
}

// Reconstruct original array via prefix sum
vector<int> buildArray(const vector<int>& diff, int n) {
    vector<int> result(n);
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr += diff[i];
        result[i] = curr;
    }
    return result;
}
```

2. Difference Array on an Existing Non-Zero Array:
```cpp
// Initialize difference array from an existing array nums
vector<int> diff(n + 1, 0);
diff[0] = nums[0];
for (int i = 1; i < n; ++i) {
    diff[i] = nums[i] - nums[i - 1];
}

// Apply updates in O(1):
diff[l] += val;
diff[r + 1] -= val;

// Reconstruct:
nums[0] = diff[0];
for (int i = 1; i < n; ++i) {
    nums[i] = nums[i - 1] + diff[i];
}
```

3. Sparse / Coordinate Difference Array (`std::map`):
```cpp
// For intervals [start, end) where coordinates are up to 10^9
map<int, int> timeline;

void addInterval(int start, int end, int val) {
    timeline[start] += val;
    timeline[end] -= val; // end is exclusive
}

bool checkCapacity(int capacity) {
    int currentLoad = 0;
    for (const auto& [time, delta] : timeline) {
        currentLoad += delta;
        if (currentLoad > capacity) {
            return false;
        }
    }
    return true;
}
```

4. 2D Difference Array (Subgrid Range Updates):
```cpp
// Grid size m x n. diff table size (m + 2) x (n + 2) to simplify boundaries.
vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));

// Add 'val' to submatrix (r1, c1) through (r2, c2) inclusive (1-indexed)
void update2D(int r1, int c1, int r2, int c2, int val) {
    diff[r1][c1] += val;
    diff[r1][c2 + 1] -= val;
    diff[r2 + 1][c1] -= val;
    diff[r2 + 1][c2 + 1] += val;
}

// Reconstruct the 2D grid
vector<vector<int>> build2D(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            grid[i - 1][j - 1] = diff[i][j];
        }
    }
    return grid;
}
```

Key Traps:
- Boundary conditions (inclusive vs exclusive):
  - Inclusive range $[l, r]$: update `diff[l] += val` and `diff[r + 1] -= val`.
  - Half-open range $[l, r)$ (e.g. drop-off times): update `diff[l] += val` and `diff[r] -= val`.
- Array sizing: `diff` must have size at least $N + 1$ (or $N + 2$ for 1-indexing) to safely access index `r + 1` without out-of-bounds faults.
- Large coordinates: allocating `vector<int> diff(1e9)` causes Memory Limit Exceeded (MLE). Use `std::map<int, int>` or sort discrete event timestamps instead.
- Offline vs Online limitation: difference array only supports batch updates followed by queries. If updates and range queries are interleaved dynamically, use a Segment Tree with Lazy Propagation or a Binary Indexed Tree.
- Negative remainder in cyclic shifts: for string shift problems wrapping around alphabet length 26, `(shift % 26 + 26) % 26` ensures positive shift values.
