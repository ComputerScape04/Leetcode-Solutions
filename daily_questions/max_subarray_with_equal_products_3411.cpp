/* Brute force */
/*
An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr)

get all possible subarray
calculate prod equivalent and update length
*/

class Solution {
public:
    long long gcd(long long a, long long b) {
        while(b) {
            a = a % b;
            swap(a, b);
        }

        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int getProdEquivalent(const vector<int>& sub, unsigned long long prod) {
        long long l = sub[0];
        long long g = sub[0];

        // get the GCD of the subarray
        for (int i = 1; i < sub.size(); i++) {
            g = gcd(g, sub[i]);
            l = lcm(l, sub[i]);
        }

        if (prod == g*l)
            return prod;
        return -1;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            vector<int> sub;
            unsigned long long prod = 1;
            for (int j = i; j < n; j++) {
                sub.push_back(nums[j]);
                prod *= (unsigned long long)nums[j];
                if (getProdEquivalent(sub, prod) != -1) {
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};

/* O(n^2 log m) Solution */
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];

            for (int j = i+1; j < nums.size(); j++) {
                prodVal *= nums[j];
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);

                if (prodVal > gcdVal * lcmVal)
                    break;
                if (prodVal == gcdVal * lcmVal)
                    res = max(res, j - i + 1);
            }
        }

        return res;
    }
};


