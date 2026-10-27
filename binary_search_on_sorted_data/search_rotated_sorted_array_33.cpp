class Solution {
public:
    int binary_search(int l, int r, vector<int>& nums, int target) {
        while(l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (target > nums[mid])
                l = mid + 1;
            else
                r = mid;
        }

        if (nums[l] == target)
            return l;

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // edge case with only size 1 array
        if (n == 1) {
            if(target == nums[0]) return 0;
            else return -1;
        }

        int l = 0, r = n-1;

        // find the pivot
        while(l < r) {
            int mid = (l + r)/2;
            if (nums[mid] == target)
                return mid;
            // otherwise we narrow the search window
            if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r = mid;
        }

        // we will consider l to be the pivot
        if (target >= nums[l] && target <= nums[n-1]) {
            // perform binary search on the left segment
            return binary_search(l, n-1, nums, target);
        }

        return binary_search(0, l-1, nums, target);
    }
};
