class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic stack
        stack<int> st;

        int n = temperatures.size();
        vector<int> res(n);

        for (int i = n-1; i >= 0; i--) {
            int count = 0;
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if (st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;

            st.push(i);
        }

        return res;
    }
};
