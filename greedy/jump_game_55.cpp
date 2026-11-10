/* DP Approach */
class Solution {
public:
    int jump(vector<int> &dp, vector<int> &nums, int i, int destination) {
        if (!dp[i] || i > destination)
            return 0;

        if (i == destination)
            return 1;

        if (nums[i] == 0) {
            dp[i] = 0;
            return 0;
        }

        for (int j = 1; j <= min(nums[i], destination); j++) {
            if (dp[(i+j)] != -1)
                continue;

            int isJumpPossible = jump(dp, nums, i+j, destination);
            dp[i] = max(dp[i], isJumpPossible);

            if (dp[i] == 1)
                break;
        }

        return dp[i];
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return true;
        if (n == 2)
            return (nums[0] > 0) ? true : false;

        vector<int> dp(n, -1);
        return jump(dp, nums, 0, n-1);
    }
};
/**********************************/

/* Greedy Approach */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int i = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (maxJump < i)
                return false;
            maxJump = max(nums[i] + i, maxJump);
        }

        return true;
    }
};
/*********************************/
