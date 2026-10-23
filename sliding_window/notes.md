Pattern to recognize:
    - Subarray / Substring
    - Maximum / Minimum
    - Length / Sum

Window Types:
    - Fixed-size: Window size k is constant. Expand right to k, then shift both pointers together.
    - Variable-size: Expand right to include elements; shrink left when condition breaks (or to minimize).

Core Template:
    1. Initialize `left = 0`, state tracking (sum, hash map).
    2. Loop `right` from 0 to N - 1 and add `nums[right]` to state.
    3. Shrink with `while (condition invalid)`: remove `nums[left]` from state, increment `left`.
    4. Update result using window length `right - left + 1`.

Key Traps:
    - Window length formula is always `right - left + 1`.
    - Monotonicity required: negative numbers usually break simple two-pointer sliding window (use prefix sums instead).

Resources:
    - https://youtu.be/dOonV6byDEg?si=UgxRF9wWS1TSWrr-
