class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n);
        deque<int> dq; // used to get the max value of a window sized k
        int maxSum = nums[0];

        for (int i = 0; i < n; i++) {
            // pop front if front no longer part of window sized k
            // meaning it is outisde (i - k) [less than i - k]
            while(!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            
            // get prevMax which is the max sum of the window
            // compute dp[i] = either the current number or sum of it with prevMax sum
            // update maxSum if found a larger subsequence sum
            int prevMax = dq.empty() ? 0 : dp[dq.front()];
            dp[i] = max(nums[i], nums[i] + prevMax);
            maxSum = max(maxSum, dp[i]);

            // pop back if monotonicity is violated when adding dp[i] to deque
            // maintain decreasing monotonicity such that front is always max
            while(!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            
            // push the new dp value to deque
            dq.push_back(i);
        }

        return maxSum;
    }
};
