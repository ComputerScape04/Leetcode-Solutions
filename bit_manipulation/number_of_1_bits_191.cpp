class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> bt(n);
        return bt.count();
    }
};

/** another way **/
class Solution {
public:
    int hammingWeight(int n) {
        int bitCount = 0;
        while(n) {
            bitCount += (n % 2);
            n /= 2;
        }

        return bitCount;
    }
};

/** proper way to do it **/
class Solution {
public:
    int hammingWeight(int n) {
        int bitCount = 0;

        while (n) {
            n &= (n - 1);
            bitCount++;
        }

        return bitCount;
    }
};
