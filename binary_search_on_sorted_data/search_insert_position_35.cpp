class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        // if target is smaller than nums[0] or greater than nums[size-1]
        if (target <= nums[0]) return 0;
        if (target > nums[n-1]) return n;

        int l = 0, r = n-1;

        while(l < r) {
            int mid = (l + r)/2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return (target <= nums[l]) ? l: l+1;
    }
};
