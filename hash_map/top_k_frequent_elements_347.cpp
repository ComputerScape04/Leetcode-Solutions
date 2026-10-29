class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // if there is only one number in the array
        if(nums.size() == 1)
            return {nums[0]};
        
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        vector<int> res;
        
        // find the k most frequent numbers
        while(k--) {
            int freq = 0, val;
            for (const auto& [key,v] : mp) {
                if (v > freq) {
                    freq = v;
                    val = key;
                }
            }
            res.push_back(val);
            mp.erase(val);
        }

        return res;
    }
};
