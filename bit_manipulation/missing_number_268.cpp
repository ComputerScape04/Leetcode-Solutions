class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            // get carry
            unsigned int carry = (unsigned int)(a & b) << 1;

            // get sum without carry
            a = a ^ b;

            // update b to carry
            // at some point b will be 0
            b = carry;
        }
        return a;
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n + 1) / 2;
        int sum = 0;

        for (int n : nums) {
            sum = getSum(sum, n);
            // sum += n;
        }

        return totalSum - sum;
    }
};

/** Optimal Solution **/
/*
 * A = Xor numbers from 1 to n
 * B = Xor numbers in the array nums
 * 
 * Res = A ^ B
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int x = 0;
        for (int i = 1; i <= n; i++)
            x ^= i;

        int y = 0;
        for (int i = 0; i < n; i++)
            y ^= nums[i];

        return x^y;
    }
};
