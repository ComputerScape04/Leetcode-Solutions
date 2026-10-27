class Solution {
public:
    void findFirst(vector<int>& nums, int target, int n, int* res_i) {
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                *res_i = mid;
                r = mid - 1;
            }
            else if (target < nums[mid]) 
                r = mid - 1;
            else
                l = mid + 1;
        }
    }

    void findLast(vector<int>& nums, int target, int n, int *res_j) {
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                *res_j = mid;
                l = mid + 1;
            }
            else if (target < nums[mid]) 
                r = mid - 1;
            else
                l = mid + 1;
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        if (n == 0) return {-1, -1};
        if (n == 1) {
            if (nums[0] == target) return {0, 0};
            else return {-1, -1};
        }

        int res_i = -1, res_j = -1;
        findFirst(nums, target, n, &res_i);
        findLast(nums, target, n, &res_j);

        return {res_i, res_j};
    }
};
