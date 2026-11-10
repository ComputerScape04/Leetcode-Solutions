class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n);   
        steps[0] = 0;

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j <= min(n-1, (i + nums[i])); j++) {
                if (!steps[j])
                    steps[j] = steps[i] + 1;
            }
        }

        return steps[n-1];
    }
};
