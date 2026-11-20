/* bottom-up solution */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;

        vector<int> dp(n+1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }
};


/* top-down solution */
class Solution {
public:
    int ways(vector<int>& memo, int n) {
        if (n == 0 || n == 1)
            return 1;

        if (memo[n] != -1) return memo[n];

        return memo[n] = ways(memo, n-1) + ways(memo, n-2);
    }

    int climbStairs(int n) {
        vector<int> memo(n+1, -1);

        return ways(memo, n);
    }
}
