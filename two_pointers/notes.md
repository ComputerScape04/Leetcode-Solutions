When to look for a two-pointer approach:
- The input array or string is sorted, or sorting it does not violate time constraints (O(n log n) is acceptable).
- You need to find pairs, triplets, or subarrays satisfying a condition or target sum.
- You need to compare or swap elements from opposite ends moving inward.
- You need to modify an array in-place without using extra space (O(1) memory requirement).
- You are working with a linked list or cyclic sequence where cycle detection or finding a midpoint is needed.
- You are comparing or merging two different sorted sequences at the same time.

Common problem types and pointer setups:
- Opposite ends (left and right moving inward):
  - Target sum pairs / triplets (e.g., Two Sum II, 3Sum).
  - Palindrome checking and string reversals (e.g., Valid Palindrome, Reverse String).
  - Boundary and area problems where greedy choices eliminate one side (e.g., Container With Most Water, Trapping Rain Water).
- Fast and slow (same direction at different speeds):
  - Cycle detection in linked lists or arrays (Floyd's Tortoise and Hare).
  - Finding the middle node of a linked list.
- Read and write pointers (same direction at conditional speeds):
  - In-place deduplication and element removal (e.g., Remove Duplicates from Sorted Array, Move Zeroes).
  - Partitioning elements (e.g., Sort Colors / Dutch National Flag).
- Two separate arrays / strings (one pointer in each):
  - Subsequence checks (e.g., Is Subsequence).
  - Merging two sorted collections (e.g., Merge Sorted Array).
