class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
        // base condition
        if (index == nums.size()) {
            res.push_back(curr);
            return;
        }

        // choose value at current index
        curr.push_back(nums[index]);

        // recurse by including nums[i]
        backtrack(index+1, nums, curr, res);

        // undo the prev choice
        curr.pop_back();

        // recurse by not including nums[i]
        backtrack(index+1, nums, curr, res);        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(0, nums, curr, res);

        return res;
    }
};
