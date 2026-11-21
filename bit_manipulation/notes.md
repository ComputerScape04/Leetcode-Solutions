# Bit Manipulation

## Signals
- Problems involving parity, single unique numbers among duplicates, or subsets ($N \le 20$).
- Space constraint requires $O(1)$ memory without extra hash sets.
- Arithmetic without using `+`, `-`, `*`, `/`.

## Useful Observations
- **Brian Kernighan’s Trick (`n & (n - 1)`)**: Strips the lowest set bit in $O(1)$; counts set bits in $O(\text{set bits})$ instead of 32 iterations.
- **Lowest Set Bit Isolation (`n & (-n)`)**: Isolates the lowest set bit to separate numbers into two disjoint XOR groups (e.g. Single Number III).
- **Self-Inverse XOR (`x ^ x = 0`, `x ^ 0 = x`)**: Cancels all identical pairs in a single pass with zero extra space.
- **Bitmask as Compact Set**: Represent visited states or subsets with an integer: test with `(mask >> i) & 1`, set with `mask |= (1 << i)`, toggle with `mask ^= (1 << i)`.
- **Carry via Shifted AND**: Addition without `+` decomposes into `sum = a ^ b` and `carry = (a & b) << 1`.

## Essential Bit Hacks
- `(n >> i) & 1`: Check if $i$-th bit is set.
- `n |= (1U << i)`: Set $i$-th bit to 1.
- `n &= ~(1U << i)`: Clear $i$-th bit to 0.
- `n ^= (1U << i)`: Toggle $i$-th bit.
- `n & (n - 1)`: Clear lowest set bit.
- `n & (-n)`: Extract lowest set bit.
- `(n > 0) && ((n & (n - 1)) == 0)`: Check if $n$ is power of 2.

## Key Variations
- **Single Unique Element**: XOR all numbers (LC 136).
- **Element Appearing Once, Others Thrice**: Count bits modulo 3 across 32 bit positions (LC 137).
- **Missing Number in $[0, n]$**: XOR all indices and values together (LC 268).
- **Counting Bits for $0 \dots n$**: DP transition: `dp[i] = dp[i >> 1] + (i & 1)` (LC 338).

## Code Skeleton
```cpp
// Hamming Weight (Brian Kernighan)
int countSetBits(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Clears lowest set bit
        count++;
    }
    return count;
}
```

## Traps
- **Operator Precedence**: Bitwise operators (`&`, `|`, `^`) have lower precedence than comparison operators (`==`, `!=`, `<`). Always wrap bit operations in parentheses: `(n & 1) == 0`.
- **Signed Integer Shifts**: Shifting signed integers or shifting by $\ge 32$ bits causes undefined behavior; cast to `unsigned int` (`1U << i`).
- **Negative Number Right Shifts**: Arithmetic right shift on signed types preserves the sign bit; use unsigned types for logical shift.
