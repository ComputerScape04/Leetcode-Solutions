class Solution {
public:
    void backtrack(int curr, const int n, const int k, vector<int>& path, vector<vector<int>>& res) {
        // size k reached
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // if curr val is out of bounds
        if (curr > n)
            return;

        // choose curr value
        path.push_back(curr);

        backtrack(curr+1, n, k, path, res);

        path.pop_back();

        backtrack(curr+1, n, k, path, res);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        
        backtrack(1, n, k, path, res);

        return res;
    }
};
