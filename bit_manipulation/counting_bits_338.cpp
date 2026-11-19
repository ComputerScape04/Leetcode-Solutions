class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        for (int i = 1; i <= n; i++) {
            int m = i;
            while(m) {
                // eliminates one set bit at a time
                m &= (m-1);
                res[i]++;
            }
        }

        return res;
    }
};
