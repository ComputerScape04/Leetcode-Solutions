class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        vector<int> res(n, -1);

        int i = n-1, piv = -1;
        // storing index rather than the value
        while(i >= 0) {
            while(!st.empty() && nums[i] >= nums[st.top()])
                st.pop();

            if (!st.empty())
                res[i] = nums[st.top()];
            else
                piv = i;

            st.push(i--);
        }

        // adjust next greater value for elements after piv
        // for (int i = piv+1; i < n; i++) {
        //     if (idx[i] != -1)
        //         continue;

        //     for (int j = 0; j <= piv; j++) {
        //         if (nums[j] > nums[i]) {
        //             idx[i] = j;
        //             break;
        //         }
        //     }
        // }

        // O(N) optimization of the above
        for (int i = n - 1; i > piv; i--) {
            while(!st.empty() && nums[i] >= nums[st.top()])
                st.pop();

            // only update if pass 1 resulted -1
            if (res[i] == -1 && !st.empty())
                res[i] = nums[st.top()];
            
            st.push(i);
        }

        // vector<int> res;
        // for (int i : idx) {
        //     if (i == -1)
        //         res.push_back(-1);
        //     else
        //         res.push_back(nums[i]);
        // }

        return res;
    }
};
