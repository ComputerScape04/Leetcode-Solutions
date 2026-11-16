# Linked List Manipulation

## Signals
- Rearranging nodes in-place (pairwise swap, reverse in $k$-groups).
- Merging multiple sorted lists into one.
- Partitioning, interleaving, or reordering list segments.

## Key Variations
- **Sentinel / Dummy Node**: `ListNode dummy(0); ListNode* curr = &dummy;` anchors the head and avoids branching.
- **K-Group / Pair Reversal**: Count $k$ nodes ahead; reverse the group; reconnect `prevTail->next` to group head and tail to next group.
- **Merge K Sorted Lists**:
  - *Divide & Conquer*: Pairwise merge lists iteratively in $O(N \log k)$ time, $O(1)$ space.
  - *Min-Heap*: Maintain a priority queue of current heads in $O(N \log k)$ time.

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
- **Dangling Local Nodes**: Never do `ListNode node(val); curr->next = &node;` inside a loop; local stack variables destruct when out of scope. Use existing nodes or `new`.
- **Lost Next Pointer**: Always save `ListNode* nxt = curr->next` before breaking or rewiring `curr->next`.
- **Dangling Tail**: Explicitly set the detached tail's `next = nullptr` to avoid cycles.
