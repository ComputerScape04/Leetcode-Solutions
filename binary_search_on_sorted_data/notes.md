# Binary Search on Sorted Data

### Recognition
- Array is sorted, partially sorted, or rotated.
- Monotonic predicate: `f(x)` is `[F, F, ..., T, T]` (or vice versa).
- Demands $O(\log N)$ runtime instead of $O(N)$.
- Target is a boundary, insertion index, peak, or inflection point.

### Common Patterns
- **Classic Search**:
  - Target value or insertion index (*Binary Search*, *Search Insert Position*).
- **First / Last Occurrence (Lower / Upper Bound)**:
  - First element $\ge target$: if `nums[mid] >= target`, `high = mid`; else `low = mid + 1`.
- **Rotated Sorted Array**:
  - Locate inflection pivot or identify which half is normally sorted (*Search in Rotated Sorted Array*).
- **Peak Finding**:
  - Compare neighbors: if `nums[mid] < nums[mid + 1]`, peak is to the right (`low = mid + 1`); else to the left (`high = mid`).
- **2D Monotonic Matrix**:
  - Flatten index `row = mid / cols`, `col = mid % cols` (*Search a 2D Matrix*).

### Core Steps
1. Set boundaries: `low = 0`, `high = n - 1` (or `n` for insertion position).
2. While `low <= high`:
   - Compute midpoint: `mid = low + (high - low) / 2`.
   - If `nums[mid] == target`: return `mid`.
   - Discard half: `low = mid + 1` or `high = mid - 1`.

### Key Traps
- **Integer Overflow**: Use `low + (high - low) / 2` instead of `(low + high) / 2`.
- **Loop Invariants**:
  - `while (low <= high)` pairs with `high = mid - 1` and `low = mid + 1`.
  - `while (low < high)` pairs with `high = mid` and `low = mid + 1` (guarantees termination).
- **Duplicates in Rotated Arrays**: When `nums[low] == nums[mid] == nums[high]`, worst-case degrades to $O(N)$; shrink bounds (`low++`, `high--`).
