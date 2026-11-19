class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned shift = 1;
        unsigned res = 0;
        
        // go through each bit from 0 to 31
        // for each number, count set bit at position i
        // at the end, mod the sum with 3
        // if the result of the mod is 1, that means 
        // the single number has a bit set in that position
        for (int i = 0; i < 32; i++) {
            int countSetBits = 0;
            for (int n : nums) {
                bitset<32> bt(n);

                if (bt.test(i))
                    countSetBits++;
            }
            
            if (countSetBits % 3)
                res += shift;

            shift *= 2;
        }

        return res;
    }
};

/** bit manipulation solution */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (int n : nums) {
            ones = (n ^ ones) & (~twos);
            twos = (n ^ twos) & (~ones);
        }

        return ones;
    }
};
