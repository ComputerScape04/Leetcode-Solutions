class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        // sort the nums array
        sort(nums.begin(), nums.end());
        
        int result;
        int diff = 1e5;
        
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = n-1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int d = target - sum;
                
                if (abs(d) < diff) {
                    diff = abs(d);
                    result = sum;
                }

                if (d < 0)
                    r--;
                else
                    l++;
            }
        }

        return result;
    }
};
