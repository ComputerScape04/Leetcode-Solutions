class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        // identify the [min, max] range to apply binary search on
        int l = 1, r = -1;
        for (int i = 0; i < piles.size(); i++) {
            l = min(l, piles[i]);
            r = max(r, piles[i]);
        }

        // apply binary search between the ranges l and r
        int res;
        while(l <= r) {
            int mid = (l + r)/2;
            // check if mid can consume all bananas within hour h
            int hour_spent = 0;
            for (int i = 0; i < n; i++) {
                hour_spent = hour_spent + ((piles[i] + mid - 1) / mid);
                if (hour_spent > h)
                    break;
            }
            if (hour_spent <= h) {
                res = mid;
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }

        return res;
    }
};
