class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] >= k)
                return 1;
            else
                return -1;
        }
    
        deque<int> idx; // stores indices of potential starting points of the subarray
        vector<int> pfx(n+1); // storing prefix sums
        int minLen = 1e5 + 1;

        // calculates the prefix sum
        for (int i = 1; i <= n; i++)
            pfx[i] = pfx[i-1] + nums[i-1];

        idx.push_back(0); // initially store idx 0 as potential starting point

        for (int i = 1; i < n+1; i++) {
            // check if sum is equal or exceeds k
            // when trying to add pfx[i] to deque
            while(!idx.empty() && (pfx[i] - pfx[idx.front()]) >= k) {
                minLen = min(minLen, i-idx.front());
                idx.pop_front();
            }
            
            // check if pfx[i] is smaller than back element in deque
            // maintain increasing monotonicity
            // this is because any element smaller than the one in deque
            // as the starting point will lead to a smaller subarray with sum >= k
            while(!idx.empty() && (pfx[idx.back()] > pfx[i])) {
                idx.pop_back();
            }
            
            idx.push_back(i);
        }

        return minLen == 1e5+1 ? -1 : minLen;
    }
};
