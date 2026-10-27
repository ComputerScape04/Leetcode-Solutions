When to look for a Linked List approach:
- Sequential data where size changes dynamically and elements need $O(1)$ insertion/deletion given a pointer.
- The problem involves pointer manipulation, reordering, reversal, or cycle detection.
- Memory constraint prohibits using extra arrays ($O(1)$ auxiliary space required).

Common problem types & patterns:
- Dummy head:
  - Simplifies edge cases where the head itself changes, is removed, or merged (e.g., Remove Nth Node From End, Merge Two Sorted Lists).
- Fast and slow pointers (Floyd's Tortoise and Hare):
  - Cycle detection: slow moves 1 step, fast moves 2 steps (e.g., Linked List Cycle).
  - Cycle start: reset slow to head after collision; advance both by 1 step (e.g., Linked List Cycle II).
  - Find middle node: when fast reaches the end, slow is at the middle.
- Two-pointer offset (gap of $k$):
  - Advance fast by $n$ steps, then move both until fast hits the end (e.g., Remove Nth Node From End of List).
- In-place reversal:
  - Maintain `prev = nullptr`, `curr = head`, and `next = nullptr` (e.g., Reverse Linked List, Reverse Nodes in k-Group).

Core Templates:

1. Dummy Head Setup:
```cpp
ListNode* dummy = new ListNode(0, head);
ListNode* curr = dummy;
// Perform operations
ListNode* result = dummy->next;
delete dummy;
return result;
```

2. In-Place Reversal:
```cpp
ListNode* prev = nullptr;
ListNode* curr = head;
while (curr != nullptr) {
    ListNode* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
}
return prev;
```

3. Fast & Slow (Middle / Cycle):
```cpp
ListNode* slow = head;
ListNode* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```

Key Traps:
- Null pointer dereference: always check `fast != nullptr && fast->next != nullptr` before doing `fast->next->next`.
- Lost references: save `curr->next` to a temporary pointer before re-linking `curr->next`.
- Memory leaks: delete dynamically allocated dummy nodes in C++ before returning.
- Infinite loops: forgeting to advance pointers (`curr = curr->next`) inside `while` loops.
