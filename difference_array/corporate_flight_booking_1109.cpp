class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flightSeatDiff(n);
        vector<int> finalSeatOccupancy(n);

        for (auto b : bookings) {
            flightSeatDiff[b[0]-1] += b[2];
            if (b[1] >= n) continue;
            flightSeatDiff[b[1]] -= b[2];
        }

        finalSeatOccupancy[0] = flightSeatDiff[0];
        for (int i = 1; i < n; i++)
            finalSeatOccupancy[i] = finalSeatOccupancy[i-1] + flightSeatDiff[i];

        return finalSeatOccupancy;
    }
};
