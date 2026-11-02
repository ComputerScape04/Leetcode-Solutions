class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> capacityAtDist(1001);
        
        int n = trips.size();
        for(int i = 0; i < n; i++) {
            capacityAtDist[trips[i][1]] += trips[i][0];
            capacityAtDist[trips[i][2]] -= trips[i][0];
        }

        // calculate running sum from the difference array
        // if the running sum ever exceeds capacity, then return false
        int sum = 0;
        for (int i = 0; i < 1001; i++) {
            sum += capacityAtDist[i];
            if (sum > capacity)
                return false;
        }

        return true;
    }
};
