class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        // r is going to be the sum of all weights
        int l = 1, r = 0, res;
        for (int c : weights)
            r += c;
        
        // apply binary search on the range [l, r]
        while(l <= r) {
            int mid = (l + r) / 2;
            // check if mid can hold all weights within days count
            int day_count = 0, sum = 0, i = 0;
            while(day_count <= days && i < n) {
                sum += weights[i];
                // max capacity reached for that day
                if (sum == mid) {
                    sum = 0;
                    day_count++;
                    i++;
                }
                else if (sum > mid) {
                    sum = 0;
                    day_count++;
                }
                else
                    i++;
            }

            // above while loop will miss a day if sum < mid and we reach end of the array
            if (sum < mid && sum != 0)
                day_count++;

            if (i == n && day_count <= days) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return res;
    }
};
