class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // directly add all 3 and check if sum is 0
        if (n == 3 && (nums[0] + nums[1] + nums[2]) == 0)
            return {nums}; 

        // sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        // for each number, perform the 2sum
        for (int i = 0; i < nums.size()-2; i++) {
            // if the second number is same as prev, skip it
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            // perform 2sum
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(nums[l] == nums[l-1] && l < r)
                        l++;
                }
                else if (sum > 0)
                    r--;
                else
                    l++;
            }
        }

        return res;
    }
};
