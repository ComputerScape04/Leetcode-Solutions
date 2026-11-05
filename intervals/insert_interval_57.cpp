class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        // find the first interval from the left
        // whose end >= new interval start
        auto left = lower_bound(intervals.begin(), intervals.end(), newInterval[0],
            [](const vector<int>& interval, int target) {
                return interval[1] < target;
            });

        // find the first interval from the right
        // whose start <= new interval end
        auto right = upper_bound(intervals.begin(), intervals.end(), newInterval[1],
            [](int target, const vector<int>& interval) {
                return interval[0] > target;
            });

        // insert into res, everything strictly to the left
        res.insert(res.end(), intervals.begin(), left);

        // if left and right are same, there are no overlaps
        if (left == right) {
            res.push_back(newInterval);
        }
        else {
            int start = min(newInterval[0], left[0][0]);
            int end = max(newInterval[1], (right-1)[0][1]); // right points to the non-overlapping interval
            res.push_back({start, end});
        }

        // insert the right portion of intervals into res
        res.insert(res.end(), right, intervals.end());

        return res;
    }
};
