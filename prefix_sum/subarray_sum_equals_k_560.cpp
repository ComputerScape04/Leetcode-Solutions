class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1; // to take care of edge case where sum becomes exactly equal to k
        
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // we can remove k preceding sum to get subarray sum as k
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
                mp[sum]++;
            }
            else
                mp[sum]++;
        }

        return count;
    }
};
