class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] == goal) return 1;
            else return -1;
        }
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - goal) != mp.end())
                count += mp[sum - goal];
            mp[sum]++;
        }

        return count;
    }
};
