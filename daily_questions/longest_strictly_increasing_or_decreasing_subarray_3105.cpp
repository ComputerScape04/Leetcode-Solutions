class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return n;

        int i = 0, j = 0;
        int result = 1;
        while(i < n-1) {
            int count = 1;
            // check for strictly increasing
            while(j < n-1 && nums[j] < nums[j+1]) {
                count++;
                j++;
            }
            result = max(result, count);
            
            // if there are same numbers - skip them
            while (j < n-1 && nums[j] == nums[j+1])
                j++;
            i = j;

            count = 1;
            // check for strictly decreasing
            while(j < n-1 && nums[j] > nums[j+1]) {
                count++;
                j++;
            }
            result = max(result, count);
            i = j;
        }

        return result;
    }
};
