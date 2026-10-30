class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);

        int r = ranges.size();
        for (int i = 0; i < r; i++) {
            diff[ranges[i][0]]++; // boards
            diff[(ranges[i][1] + 1)]--; // leaves
        }

        int sum = 0;
        for (int i = 0; i < 52; i++) {
            sum += diff[i];
            if (sum <= 0 && (i >= left && i <= right))
                return false;
        }

        return true;
    }
};
