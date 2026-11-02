class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return {nums[0]};

        vector<int> res;
        // monotoically decreasing deque
        deque<int> dq; // stores index

        for (int i = 0; i < k; i++) {
            // pop back if violating monotonicity
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        int i = 1, j = k;
        while(j < n) {
            // check if top belongs to current window
            while(!dq.empty() && dq.front() < i)
                dq.pop_front();

            // pop back if violating monotonicity
            while(!dq.empty() && nums[dq.back()] <= nums[j])
                dq.pop_back();

            if (dq.empty() || (nums[j] < nums[dq.back()]))
                dq.push_back(j);

            res.push_back(nums[dq.front()]);

            i++; j++;
        }

        return res;
    }
};
