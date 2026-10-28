class Solution {
public:
    /* will use stl functions in this problem */
    /* but can be solved without it */
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        // get the max value in nums --> that will be our min in [min,max] range
        int l, r, res;
        l = *max_element(nums.begin(), nums.end());
        r = accumulate(nums.begin(), nums.end(), 0);

        if (r == 0)
            return 0;

        // apply binary search in the range [l,r]
        while(l <= r) {
            int mid = (l + r)/2;

            int subarray_count = 0, i = 0, sum = 0;
            while(subarray_count != k && i < n) {
                sum += nums[i];
                i++;
                // skip any zeroes
                while(i < n && nums[i] == 0) i++;
                if (sum == mid) {
                    sum = 0;
                    subarray_count++;
                }
                else if (sum > mid) {
                    sum = 0;
                    subarray_count++;
                    i--;
                }
            }

            if (sum < mid && sum != 0)
                subarray_count++;

            // valid only if the entire array is traversed and subarray count is less than or equal to k
            if (subarray_count <= k && i == n) {
                res = mid;
                r = mid - 1;
            }
            else // mid is too restrictive, increase l
                l = mid + 1;
        }

        return res;
    }
};
