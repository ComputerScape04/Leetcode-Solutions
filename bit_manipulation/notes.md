# Bit Manipulation Cheatsheet & Notes

---

## 1. Fundamentals & Bitwise Operators

| Operator | Name | Effect | Example (`a = 5 (0101)`, `b = 3 (0011)`) |
| :---: | :---: | :--- | :--- |
| `&` | **AND** | `1` only if both bits are `1` | `5 & 3` $\rightarrow$ `0001` (1) |
| `\|` | **OR** | `1` if at least one bit is `1` | `5 \| 3` $\rightarrow$ `0111` (7) |
| `^` | **XOR** | `1` if bits are different; `0` if same | `5 ^ 3` $\rightarrow$ `0110` (6) |
| `~` | **NOT** | Inverts all bits | `~5` $\rightarrow$ `...11111010` (-6) |
| `<<` | **Left Shift** | Shifts bits left (multiplies by $2^k$) | `5 << 1` $\rightarrow$ `1010` (10) |
| `>>` | **Right Shift** | Shifts bits right (divides by $2^k$) | `5 >> 1` $\rightarrow$ `0010` (2) |

---

## 2. Essential Bit Hacks & Idioms

### Basic Bit Operations (0-indexed at position `i`)
```cpp
// Check if i-th bit is set (0 or 1)
bool isSet = (n >> i) & 1;

// Set the i-th bit to 1
n |= (1U << i);

// Clear (unset) the i-th bit to 0
n &= ~(1U << i);

// Toggle (flip) the i-th bit
n ^= (1U << i);
```

### The "Must-Know" Tricks
* **Clear the lowest set bit:**
  ```cpp
  n &= (n - 1); // 0110 -> 0100 (Brian Kernighan's trick)
  ```
* **Extract / isolate the lowest set bit:**
  ```cpp
  int lowest = n & (-n); // 0110 -> 0010
  ```
* **Check if $n$ is a power of 2 ($n > 0$):**
  ```cpp
  bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
  ```
* **Swap two variables without extra space:**
  ```cpp
  a ^= b;
  b ^= a;
  a ^= b;
  ```

---

## 3. C++ `std::bitset<N>` Quick Reference

```cpp
#include <bitset>

bitset<32> b(n); // Fixed-size bitset of 32 bits (0-indexed from right/LSB)
```

| Method | Description |
| :--- | :--- |
| `b[i]` | Accesses bit `i`. `b[0]` is LSB ($2^0$), `b[31]` is MSB ($2^{31}$). |
| `b.test(i)` | Returns `true` if $i$-th bit is 1 (throws `out_of_range` if invalid). |
| `b.count()` | Returns total number of set bits (population count). |
| `b.set(i, val)` | Sets bit `i` to `1` (or `val`). `b.set()` sets all bits to 1. |
| `b.reset(i)` | Resets bit `i` to `0`. `b.reset()` clears all bits to 0. |
| `b.flip(i)` | Inverts bit `i`. `b.flip()` inverts all bits. |
| `b.to_ulong()` | Converts bitset to `unsigned long`. |
| `b.to_string()` | Converts bitset to `std::string` of `'0'`s and `'1'`s. |

> [!WARNING]
> In `bitset<32> b`:
> * `b[0]` is the **least significant bit** ($2^0$, far right in binary string).
> * `b[31]` is the **most significant bit** ($2^{31}$, far left in binary string).

---

## 4. Key LeetCode Patterns & Solutions

### 1. Single Number I (LC 136)
> *Every element appears twice except one. Find it.*
* **Concept:** $x \oplus x = 0$ and $x \oplus 0 = x$.
```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int n : nums) ans ^= n;
    return ans;
}
```

---

### 2. Single Number II (LC 137)
> *Every element appears 3 times except one. Find it.*

#### Approach A: 32-Bit Counting (Recommended for Interviews)
* Count occurrences of the $i$-th bit across all numbers.
* If `sum % 3 != 0`, that bit belongs to the unique number.
* **Works for any frequency $k$ (e.g. elements appearing 5 times).**
```cpp
int singleNumber(vector<int>& nums) {
    unsigned int res = 0;
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        for (int n : nums) {
            sum += (n >> i) & 1;
        }
        if (sum % 3 != 0) {
            res |= (1U << i);
        }
    }
    return (int)res;
}
```

#### Approach B: 2-Bit State Machine (Hardware Counter)
* `ones`: tracks bits seen $1 \pmod 3$ times.
* `twos`: tracks bits seen $2 \pmod 3$ times.
* Resets to 0 on 3rd appearance.
```cpp
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int n : nums) {
        ones = (ones ^ n) & (~twos);
        twos = (twos ^ n) & (~ones);
    }
    return ones;
}
```

---

### 3. Missing Number (LC 268)
> *Range $[0, n]$, one number missing.*
* **Concept:** XOR all numbers from $0$ to $n$ with all numbers in `nums`. All matching pairs cancel out; only the missing one remains. No integer overflow risk compared to $\frac{n(n+1)}{2}$.
```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; i++) {
        ans ^= i ^ nums[i];
    }
    return ans;
}
```

---

### 4. Number of 1 Bits (LC 191 - Hamming Weight)
* **Brian Kernighan’s Algorithm:** Iterates only as many times as there are `1` bits ($O(\text{set bits})$).
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Clears the lowest set bit
        count++;
    }
    return count;
}
```

---

### 5. Counting Bits (LC 338)
> *Count set bits for all numbers from $0$ to $n$.*
* **DP Relation:** Number of set bits in `i` is the same as in `i >> 1` plus the last bit (`i & 1`).
```cpp
vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
        // Alternative: dp[i] = dp[i & (i - 1)] + 1;
    }
    return dp;
}
```

---

### 6. Reverse Bits (LC 190)
> *Reverse bits of a 32-bit unsigned integer.*

#### Standard Approach (Shift loop):
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    return res;
}
```

#### Divide & Conquer (5 operations, ideal for repetitive calls):
```cpp
uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8)  | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4)  | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2)  | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1)  | ((n & 0x55555555) << 1);
    return n;
}
```

---

### 7. Sum of Two Integers (LC 371)
> *Add two numbers without `+` or `-`.*
* `^` gives the sum without carry.
* `& << 1` gives the carry shifted left.
```cpp
int getSum(int a, int b) {
    while (b != 0) {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
```
