class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return {{""}};

        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string c = s;
            sort(c.begin(), c.end());
            mp[c].push_back(s);
        }

        for (auto i : mp)
            res.push_back(i.second);

        return res;
    }
};
