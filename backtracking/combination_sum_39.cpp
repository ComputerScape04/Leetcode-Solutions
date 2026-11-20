class Solution {
public:
    void backtrack(
        const vector<int> &candidates, 
        int target, 
        int index, 
        vector<int>& combination, 
        vector<vector<int>>& res) 
    {
        // out of bounds check
        if (index == candidates.size() || target < 0)
            return;

        // base condition
        if (target == 0) {
            res.push_back(combination);
            return;
        }

        // either I choose the current element or the one ahead of it
        if (index < candidates.size() && candidates[index] <= target) {
            combination.push_back(candidates[index]);
            backtrack(candidates, target - candidates[index], index, combination, res);
       
            // undo the previous consideration
            combination.pop_back();
        }

        // consider the next element in the array
        backtrack(candidates, target, index+1, combination, res);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        backtrack(candidates, target, 0, combination, res);
        return res;
    }
};
