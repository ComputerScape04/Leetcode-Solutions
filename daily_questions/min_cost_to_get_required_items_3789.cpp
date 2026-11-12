class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0)
            return 0;

        long long totalCost;

        if (cost1 + cost2 < costBoth)
            totalCost = ((long long)cost1 * (long long)need1) + ((long long)cost2 * (long long)need2);
        else {
            long long smallerNeed = min(need1, need2);
            totalCost = (long long)costBoth * smallerNeed;
            // if need 1 is smaller - need 1 is taken care of
            if (need1 < need2) {
                if (cost2 < costBoth)
                    totalCost += (long long)cost2 * (need2 - need1);
                else
                    totalCost += (long long)costBoth * (need2 - need1);
            }
            else {
                if (cost1 < costBoth)
                    totalCost += (long long)cost1 * (need1 - need2);
                else
                    totalCost += (long long)costBoth * (need1 - need2);
            }
        }

        return totalCost;    
    }
};
