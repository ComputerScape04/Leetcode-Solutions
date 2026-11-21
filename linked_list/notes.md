# Linked List

## Signals
- Dynamic sequence requiring $O(1)$ node insertion and deletion.
- Constant $O(1)$ auxiliary space constraint.
- Pointer rewiring, reversal, midpoint detection, or cycle detection.

## Useful Observations
- **Dummy Node Eliminates Head Edge Cases**: Using a sentinel node (`ListNode dummy(0, head)`) eliminates special branching when deleting or modifying the head node.
- **Fast and Slow Pointers (Floyd's Algorithm)**:
  - *Midpoint*: `slow` advances 1 step, `fast` advances 2 steps; when `fast` reaches end, `slow` is at midpoint.
  - *Cycle Detection*: Collision between `slow` and `fast` proves a cycle exists.
  - *Cycle Entrance*: After collision, reset `slow = head`; advance both 1 step at a time until they meet at the cycle entrance.
- **Fixed-Gap Pointers for N-th from End**: Advance `fast` pointer $N$ steps ahead first; then advance `slow` and `fast` together until `fast->next == nullptr`; `slow->next` is the target to delete.

## Key Variations
- **Dummy Node**: Deleting node values or removing duplicates.
- **Two Pointers (Fast / Slow)**: Midpoint retrieval and cycle detection.
- **Fixed Gap ($k$ steps)**: Removing $N$-th node from the end.

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
- **Null Pointer Dereference**: Always verify `while (fast && fast->next)` before accessing `fast->next->next`.
- **Returning Mutated Head Directly**: Returning `head` fails if the original head was deleted; return `dummy.next` instead.
- **Memory Leaks in C++**: In interview environments, remember to delete unlinked nodes if explicit cleanup is requested.
