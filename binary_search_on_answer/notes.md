When to look for a Binary Search on Answer approach:
- The problem asks to optimize a value: "find minimum $X$ such that..." or "find maximum $X$ such that...".
- The input array itself does not need to be sorted.
- The answer lies within a bounded, continuous range $[L, R]$ (e.g., speed, days, capacity).
- Monotonic feasibility property:
  - If a value $X$ is valid/possible, then every value $> X$ is also valid (finding minimum valid).
  - Or if $X$ is valid/possible, then every value $< X$ is also valid (finding maximum valid).
- A brute force linear search from $L$ to $R$ would TLE, but testing a candidate answer takes $O(N)$ time. Total time becomes $O(N \log(\text{range}))$.

Common problem types:
- Rate / speed minimization:
  - Find min speed to finish within $H$ hours (e.g., Koko Eating Bananas).
- Capacity / allocation minimization:
  - Split array into $m$ subarrays to minimize max sum (e.g., Split Array Largest Sum, Capacity To Ship Packages Within D Days).
- Distance maximization:
  - Place $k$ items such that minimum distance between any two is maximized (e.g., Aggressive Cows, Magnetic Force Between Two Balls).
- Time / work completion:
  - Minimum time needed for multiple workers/machines to complete $T$ tasks (e.g., Minimum Time to Complete Trips).

Core Template:

```cpp
bool isValid(const vector<int>& nums, long long mid, /* constraints */) {
    // Greedy or simulation check: can we satisfy the condition with 'mid'?
    // Returns true/false in O(N) or O(1) time
}

long long binarySearchOnAnswer(vector<int>& nums) {
    long long low = MIN_POSSIBLE_ANSWER;
    long long high = MAX_POSSIBLE_ANSWER;
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(nums, mid)) {
            ans = mid;           // Record candidate
            high = mid - 1;      // Minimize: search left (for maximize: low = mid + 1)
        } else {
            low = mid + 1;       // Infeasible: search right (for maximize: high = mid - 1)
        }
    }
    return ans;
}
```

Key Traps:
- Incorrect search boundaries: setting `low` or `high` too narrow excludes the true answer; setting `low = 0` when dividing by speed causes division-by-zero.
- Integer overflow: `mid * count` or `low + high` exceeding 32-bit signed integer limits; use `long long` for bounds and arithmetic.
- Direction mix-up:
  - For **minimum feasible**: `isValid(mid) == true` $\rightarrow$ try smaller (`high = mid - 1`).
  - For **maximum feasible**: `isValid(mid) == true` $\rightarrow$ try larger (`low = mid + 1`).
- Ceiling division: when calculating hours/trips, use `(val + mid - 1) / mid` instead of floating-point `ceil((double)val / mid)` to avoid precision loss.
