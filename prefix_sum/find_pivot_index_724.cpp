class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        vector<int> pfx_f(n);
        vector<int> pfx_b(n);

        pfx_f[0] = nums[0];
        pfx_b[n-1] = nums[n-1];

        // calculate both forward and backward prefix sums
        for (int i = 1, j = n-2; i < n, j >= 0; i++, j--) {
            pfx_f[i] = pfx_f[i-1] + nums[i];
            pfx_b[j] = pfx_b[j+1] + nums[j];
        }

        // if there is a value that is the same, in the same index, then
        // that index is the answer
        for (int i = 0; i < n; i++)
            if (pfx_f[i] == pfx_b[i])
                return i;
            
        return -1;
    }
};
