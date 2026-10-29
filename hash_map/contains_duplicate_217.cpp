class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> table;
        for (int x : nums) 
            table.insert(x);
        return (table.size() == nums.size()) ? false : true;
    }
};
