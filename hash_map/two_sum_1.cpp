class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int secondVal = target - nums[i];
            // pair isn't in the hash map
            if (mp.find(secondVal) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[secondVal], i};
        }

        return {};
    }
};
