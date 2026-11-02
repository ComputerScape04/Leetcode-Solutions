class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1)
            return heights[0];

        // monotonic increasing stack
        stack<pair<int, int>> st; // storing {idx,val}
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            pair<int, int> lastPopped = {-1,-1};
            // pop until we find a smaller histogram bar
            // simultaneously calculate the area of the rectangle popped
            while(!st.empty() && heights[i] < st.top().second) {
                maxArea = max(maxArea, st.top().second * (i - st.top().first));
                lastPopped = st.top();
                st.pop();
            }

            if (lastPopped.first == -1)
                st.push({i, heights[i]});
            else
                // this histogram bar can be extended backwards
                st.push({lastPopped.first, heights[i]});
        }

        // if the stack isn't empty, 
        // those values reach can be extended till the end of the histogram
        while(!st.empty()) {
            pair<int, int> p = st.top();
            maxArea = max(maxArea, p.second * (n - p.first));
            st.pop();
        }
        
        return maxArea;
    }
}; 
