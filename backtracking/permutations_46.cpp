class Solution {
public:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<int>& used, vector<vector<int>>& res) {
        // base case
        if (current.size() == nums.size())
            res.push_back(current);
        
        // choice
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            
            // pick the unchosen number and add it to the current path
            current.push_back(nums[i]);
            used[i] = 1;

            // recurse further
            backtrack(nums, current, used, res);

            // undo the previous choice
            current.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used(nums.size());
        vector<int> current;

        backtrack(nums, current, used, res);
        return res;
    }
};
