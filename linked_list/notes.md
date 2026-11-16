# Linked List

## Signals
- Dynamic sequence requiring $O(1)$ node insertion/deletion.
- $O(1)$ auxiliary space constraint.
- Pointer rewiring, reversal, midpoint, or cycle detection.

## Key Variations
- **Dummy Node (`ListNode dummy(0, head)`)**: Eliminates edge cases when deleting, inserting, or modifying the head.
- **Fast & Slow Pointers**:
  - *Midpoint*: `slow` moves 1 step, `fast` moves 2 steps.
  - *Cycle Detection*: Collision implies cycle (Floyd's algorithm).
  - *Cycle Entry*: Reset `slow = head`; move both 1 step until they meet.
- **Fixed Gap ($k$ steps)**: Advance `fast` by $k$ steps first, then advance both together (e.g. *Remove Nth from End*).

## Code Skeleton
```cpp
// Midpoint / Cycle Detection
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
        // Cycle detected
        break;
    }
}
```

## Traps
- **Null Pointer Dereference**: Always check `while (fast && fast->next)` before calling `fast->next->next`.
- **Modifying Head Directly**: Returning modified `head` fails if the original head was deleted; return `dummy.next` instead.
- **Dangling Cycles**: After rearranging segments, always set the new tail's `next = nullptr`.
