class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        
        vector<vector<int>> res; // holds merged intervals
        sort(intervals.begin(), intervals.end()); // sort based on start(i)

        // if end[i] >= start[i+1], then we merge i and i+1'th intervals
        int i = 0;
        while(i < n) {
            int j = i;
            int largestEnd = intervals[j][1];
            // find the largest boundary
            while(j < n-1 && largestEnd >= intervals[j+1][0]) {
                largestEnd = max(largestEnd, max(intervals[j][1], intervals[j+1][1]));
                j++;
            }
            res.push_back({intervals[i][0], largestEnd});
            i = j+1;
        }

        return res;
    }
};
