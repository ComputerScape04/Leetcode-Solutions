class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 1)
            return 1;
        
        deque<int> mindq; // monotonically increasing
        deque<int> maxdq; // monotonically decreasing
        int maxLen = 1;

        int i = 0, j = 0;
        while(i < n && j < n) {
            // maintain increasing monotonicity
            while(!mindq.empty() && nums[mindq.back()] > nums[j])
                mindq.pop_back();

            // maintain decreasing monotonicity
            while(!maxdq.empty() && nums[maxdq.back()] < nums[j])
                maxdq.pop_back();

            mindq.push_back(j);
            maxdq.push_back(j);

            // limit has been violated
            // maxdq front will hold the largest value in the window
            // mindq front will hold the smallest value in the window
            // window is [i,j]
            if (abs(nums[maxdq.front()] - nums[mindq.front()]) > limit)
                i++;
            
            // if i is incremented, either maxdq or mindq might have index out of bound
            // check front in both deques are within bound
            if (maxdq.front() < i)
                maxdq.pop_front();
            if (mindq.front() < i)
                mindq.pop_front(); 

            maxLen = max(j - i + 1, maxLen);
            j++;
        }

        return maxLen;
    }
};
