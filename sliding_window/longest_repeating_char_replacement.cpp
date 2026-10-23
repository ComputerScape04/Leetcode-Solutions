class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // character count in the window
        unordered_map<char, int> mp;

        int n = s.size(); 
        if (n == 1)
            return 1;

        int i = 0, j = 0;
        int res_len = 1;

        while(j < n) {

            mp[s[j]]++;

            // most freq char count
            int cnt = -1;

            for (const auto& [k, v] : mp) {
                if (v > cnt) {
                    cnt = v;
                }
            }

            // check for the satisfying condition
            if (((j - i + 1) - cnt) <= k) {
                // cout << "i : " << i << " j : " << j << endl;
                res_len = max(res_len, (j - i + 1));
            }
            else {
                // exclude the count of the char from the previous window
                mp[s[i]]--;
                i++;
            }

            j++;
        }

        return res_len;
    }
};
