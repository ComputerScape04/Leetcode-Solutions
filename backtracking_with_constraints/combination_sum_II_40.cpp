class Solution {
public:
    void backtrack(
        const vector<int>& candidates, 
        int target, 
        int index, 
        vector<int>& combinations, 
        vector<vector<int>>& res
    ) {
        // 1 2 2 2 5
        // if target is reached
        if (target == 0) {
            res.push_back(combinations);
            return;
        }

        // out of bounds check
        if (index == candidates.size() || target < 0)
            return;

        // choose index if element at index is smaller or equal to target
        if (candidates[index] <= target) {
            combinations.push_back(candidates[index]);
            backtrack(candidates, target - candidates[index], index + 1, combinations, res);
            
            // remove the previously considered element
            combinations.pop_back();
        }

        // ignore duplicates in the solution set (if previously already considered)
        while(index < candidates.size()-1 && candidates[index] == candidates[index+1])
            index++;

        backtrack(candidates, target, index+1, combinations, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combinations;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combinations, res);

        return res;
    }
};
