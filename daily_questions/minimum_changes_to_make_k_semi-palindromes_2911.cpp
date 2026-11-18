class Solution {
public:
    int calcCost(const string& s, int i, int j) {
        int len = j - i + 1;
        // if len is less than 2, then divisor is not possible
        if (len < 2)
            return 1e9;

        // calculate all possible divisors for the len
        vector<int> divisors;
        for (int i = 1; i < len; i++)
            if (len % i == 0)
                divisors.push_back(i);

        // for each divisor identify, which leads to minimum cost
        // to convert substring to palindrome
        int min_changes = 1e9;
        for (int d : divisors) {
            int total_cost_for_d = 0;
            
            // for each group r
            for (int r = 0; r < d; r++) {
                
                string group = "";
                for (int idx = i + r; idx <= j; idx += d)
                    group += s[idx];

                // calculate cost to make it a palindrome
                int left = 0, right = group.size()-1;
                while(left < right)
                    if (group[left++] != group[right--])
                        total_cost_for_d++;
            }

            min_changes = min(min_changes, total_cost_for_d);
        }

        return min_changes;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();
        
        vector<vector<int>> cost(n, vector<int>(n));
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9)); // length of string n divided into k pieces

        // precompute the cost table for all possible substrings of s
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cost[i][j] = calcCost(s, i, j);

        // construct the dp table
        dp[0][0] = 0; // cost of dividing string of len 0 into 0 pieces is 0

        // start from 1 piece to k pieces
        for (int p = 1; p <= k; p++) {
            // substring of length i (prefixing the last substring j)
            for (int i = 1; i <= n; i++) {
                // final substring j => [j, i-1]
                for (int j = 0; j <= i-1; j++) {
                    // cost for making substring of length i into p pieces into a semi-palindrome
                    // is equal to cost of substring of length j divided into p-1 pieces + cost of
                    // substring of length i - 1 + j ( the last substring )
                    dp[i][p] = min(dp[i][p], dp[j][p-1] + cost[j][i-1]);
                }
            }
        }

        return dp[n][k];
    }
};
