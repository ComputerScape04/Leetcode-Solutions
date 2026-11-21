# Linked List Manipulation

## Signals
- In-place node rearrangement (pairwise swap, reversal in $k$-groups).
- Merging multiple sorted lists into one.
- Partitioning, interleaving, or reordering list segments.

## Useful Observations
- **Three-Pointer In-Place Reversal**: Maintain `prev = nullptr`, `curr = head`, and `nxt = curr->next`; reverse links iteratively in $O(1)$ space.
- **Save Before Rewire**: Always save `ListNode* nxt = curr->next` into a temporary variable *before* changing `curr->next` to prevent losing the remaining list.
- **Divide and Conquer for Merge K Lists**: Pairwise merging $K$ lists iteratively achieves $O(N \log K)$ time and $O(1)$ extra space, outperforming repetitive sequential merging ($O(N \cdot K)$).
- **Detached Segment Termination**: When splitting a list (e.g. before reversing second half in Reorder List), explicitly set `prev->next = nullptr` to terminate the first half.

## Key Variations
- **Sublist Reversal**: Invert pointers between node $L$ and node $R$.
- **Reverse in K-Groups**: Check for $k$ remaining nodes, reverse the group, and attach boundaries.
- **Merge K Sorted Lists**: Use Min-Heap or iterative divide-and-conquer.
- **List Partitioning**: Separate into `< x` and `\ge x` lists using two dummy nodes, then link them.

## Code Skeleton
```cpp
// In-place sublist reversal
ListNode* reverse(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
```

## Traps
- **Dangling Local Stack Nodes**: Never assign `curr->next = &localNode`; stack objects destruct when exiting scope.
- **Cycle Creation via Un-cleared Tail**: Leaving the old head pointing to subsequent nodes after reversal produces infinite cycles.
- **Lost Segment Connections**: In $k$-group reversal, failing to bridge `prevGroupTail->next` to the newly reversed group head disconnects the list.
