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

            // if the current element is a duplicate
            // and if the previous element is not part of the current active path
            // then the current number will lead to duplicate permutation.
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
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

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used(nums.size());
        vector<int> current;

        // sort the array to bring duplicates together
        sort(nums.begin(), nums.end());

        backtrack(nums, current, used, res);
        return res;
    }
};
