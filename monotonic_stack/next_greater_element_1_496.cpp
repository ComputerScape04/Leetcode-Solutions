class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nextGreater(1e4 + 1);
        vector<int> res(m);
        
        // monotonically decreasing stack
        stack<int> st;
        int i = n-1;

        while(i >= 0) {
            // pop all smaller elements
            while(!st.empty() && nums2[i] >= st.top())
                st.pop();
            
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i--]);
        }

        for (int i = 0; i < m; i++)
            res[i] = nextGreater[nums1[i]];    

        return res;
    }
};
