class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        // stores the result
        int max_len = 0;
        
        // sort the input array once at the beginning 
        sort(nums.begin(), nums.end());

        // stores length of sequence ending at any value i 
        // where i is between 0 and largest element of nums
        vector<int> dp(nums[n-1]+2);

        for (int x : nums) {
            dp[x+1] = dp[x] + 1;
            dp[x] = dp[x-1] + 1;
            max_len = max({max_len, dp[x], dp[x+1]});
        }

        return max_len;
    }
};
