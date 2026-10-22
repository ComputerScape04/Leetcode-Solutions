class Solution {
public:
    // extract the resulting substring between the indices i and j
    string extract_substring(int i, int j, string s) {
        string res = "";

        for (; i <= j; i++)
            res += s[i];

        return res;
    }

    string minWindow(string s, string t) {

        int m = s.size();
        int n = t.size();

        // if m < n, then return ""
        if (m < n)
            return "";

        // 2 hashmaps
        // One for the char(t) count (need)
        // Other for the window count (have)
        unordered_map<char, int> need;
        unordered_map<char, int> have;

        // 'have' and 'need' counts
        int h = 0, ne;

        for (int i = 0; i < n; i++) {
            need[t[i]]++;
            have[t[i]] = 0;
        }

        ne = need.size();

        // resultant indices and length
        int res_i = -1, res_j = -1, len = 1000000;

        int i = 0, j = 0;

        // main loop - traversing string s
        while (j < m) {
            // check if s[j] belongs to t
            // if yes, update the 'have' map and 'h' accordingly
            if (have.find(s[j]) != have.end()) {
                have[s[j]]++;

                // check if have = need for s[j]
                if (have[s[j]] == need[s[j]])
                    h++;
            }

            // check if have = need, we have a valid result
            if (h == ne) {
                if ((j - i + 1) < len) {
                    len = j - i + 1;
                    res_i = i;
                    res_j = j;
                }

                cout << res_i << " " << res_j << endl;

                // shrink the window by moving i pointer
                while (h == ne) {
                    if (have.find(s[i]) == have.end()) {
                        i++;
                        continue;
                    }
                    if ((j - i + 1) < len) {
                        len = j - i + 1;
                        res_i = i;
                        res_j = j;
                    }
                    have[s[i]]--;
                    if (have[s[i]] < need[s[i]]) {
                        h--;
                    }
                    i++;
                }
            }

            j++;
        }

        return (res_i == -1 && res_j == -1)
                   ? ""
                   : extract_substring(res_i, res_j, s);
    }
};
