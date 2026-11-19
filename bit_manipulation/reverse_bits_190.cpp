class Solution {
public:
    int reverseBits(int n) {
        bitset<32> b(n);
        
        int i = 0, j = 31;
        while(i <= j) {
            int temp = b[i];
            b.set(i, b[j]);
            b.set(j, temp);
            i++;
            j--;
        }

        return (int)b.to_ulong();
    }
};

/** optimal solution **/
class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;

        for (int i = 0; i < 32; i++) {
            res = res << 1; // moving bit position
            int bit = n % 2; // getting last bit from input
            res += bit; // adding it to res
            n = n >> 1; // strip the last bit from input
        }

        return res;
    }
};
