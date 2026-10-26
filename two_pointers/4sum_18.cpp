class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;

        for (int i = 0; i < n-3; i++) {
            // skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // pruning was suggested by AI as an optimization (not part of my original solution)
            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;                                      
            if ((long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i+1; j < n-2; j++) {
                // skip if j and j-1'th ints were same
                if (j != i+1 && nums[j] == nums[j-1]) continue;

                // pruning was suggested by AI as an optimization (not part of my original solution)
                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;                                      
                if ((long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int l = j+1, r = n-1;

                while(l < r) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];

                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while(nums[l] == nums[l-1] && l < r)
                            l++;
                    }
                    else if (sum < target)
                        l++;
                    else
                        r--;
                }

            }
        }

        return res;
    }
};
