class Solution {
public:
    int firstLast(vector<int> nums, int n) {
        nums[0] = nums[1];
        nums[n-1] = nums[n-2];
        return nums[n-1] - nums[0];
    }

    int firstTwo(vector<int> nums, int n) {
        nums[0] = nums[1] = nums[2];
        return nums[n-1] - nums[0];
    }

    int lastTwo(vector<int> nums, int n) {
        nums[n-1] = nums[n-2] = nums[n-3];
        return nums[n-1] - nums[0];
    }

    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return min(firstLast(nums, n), min(firstTwo(nums, n), lastTwo(nums, n)));
    }
};
