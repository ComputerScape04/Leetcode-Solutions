/* Optimal Solution (non DP) */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.size()-1, j = t.size()-1;

        while(i > -1 && j > -1) {
            if (s[i] == t[j])
                i--;
            j--;
        }

        return i == -1 ? 1 : 0;
    }
};

/* DP Solution 1 (Not so optimal) */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // if s is empty, s is automatically a subsequence of t
        for (int i = 0; i <= n; i++)
            dp[0][i] = true;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};
