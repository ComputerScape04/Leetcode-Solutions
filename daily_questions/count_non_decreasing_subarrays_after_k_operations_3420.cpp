class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return 1;
        
        deque<pair<long long, long long>> dq; // val -> count (Monotonically decreasing)

        // sliding window - expanding and shrinking leftwards
        int i = n-1, j = n-1;
        long long subArrayCount = 0;
        long long cost = 0;

        while(i >= 0 && j >= 0) {
            int numberOfElementsPopped = 0;

            // if nums[i] violates monotonicity
            while(!dq.empty() && nums[i] > dq.back().first) {
                cost += (long long)(nums[i] - dq.back().first) * (long long)dq.back().second;
                numberOfElementsPopped += (long long)dq.back().second;
                dq.pop_back();
            }
            cout << endl;
            
            dq.push_back({nums[i], numberOfElementsPopped + 1});

            // check if cost is over k
            if (cost <= k) {
                subArrayCount += (j - i + 1);
                i--;
            }
            else {
                // otherwise shrink the window from the right
                while(i<=j && cost > k) {
                    cost -= (dq.front().first - nums[j]);
                    dq.front().second--;
                    if (dq.front().second == 0)
                        dq.pop_front();
                    j--;
                }
                subArrayCount += (j - i + 1);
                i--;
            }
        }

        return subArrayCount;
    }
};
