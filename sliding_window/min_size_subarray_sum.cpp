class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        // if array is size  1
        if (n == 1 && nums[0] == target) 
            return n; 

        // initialize result to a large value
        int res_len = 1e6;

        int i = 0, j = 0, sum = 0;

        while(j < n) {
            sum += nums[j];

            // if sum < target, increment j (adding more value)
            if (sum < target) {
                j++;
            }
            // if sum >= target, exclude nums[i] from sum and increment i -- until sum < target
            else {
                while(sum >= target) {
                    res_len = min(res_len, j - i + 1);
                    sum -= nums[i++];
                }
                j++;
            }
        }

        return (res_len == 1e6) ? 0 : res_len;
    }
};
