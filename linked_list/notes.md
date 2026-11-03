# Linked List

### Recognition
- Dynamic sequential structure requiring $O(1)$ node insertion/deletion at a pointer.
- Sub-quadratic or $O(1)$ auxiliary space constraint.
- Operations involving pointer rewiring, reversal, reordering, or cycle detection.

### Common Patterns
- **Dummy Head (`ListNode dummy(0, head)`)**:
  - Eliminates edge cases when the head node is deleted, updated, or prepended (*Merge Two Sorted Lists*, *Remove Nth Node From End*).
- **Fast & Slow Pointers**:
  - *Midpoint*: `slow` moves 1 step, `fast` moves 2 steps; when `fast` ends, `slow` is at mid.
  - *Cycle Detection*: Collision indicates a cycle (*Linked List Cycle*).
  - *Cycle Start*: Reset `slow` to `head`; move both 1 step until they meet (*Linked List Cycle II*).
- **Fixed Offset (Gap of $k$)**:
  - Advance `fast` by $k$ steps first, then move both pointers together (*Remove Nth Node From End*).
- **In-Place Reversal**:
  - Rewire pointers sequentially using `prev`, `curr`, and `next` (*Reverse Linked List*, *Reverse Nodes in k-Group*).

### Core Steps
- **In-Place Reversal**:
  1. Initialize `prev = nullptr`, `curr = head`.
  2. While `curr != nullptr`:
     - `ListNode* nxt = curr->next;`
     - `curr->next = prev; prev = curr; curr = nxt;`
  3. Return `prev`.
- **Fast & Slow**:
  1. Initialize `slow = head`, `fast = head`.
  2. While `fast && fast->next`:
     - `slow = slow->next; fast = fast->next->next;`

### Key Traps
- **Null Pointer Dereference**: Always guard `fast && fast->next` before accessing `fast->next->next`.
- **Lost Next Pointer**: Cache `curr->next` in a temporary variable before mutating `curr->next`.
- **Dangling Cycles**: Explicitly set the tail node's `next = nullptr` after segment rearrangements.
