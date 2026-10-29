class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> lookup;
        for (int x : nums)
            lookup.insert(x);
        
        int len = 1;
        for (int x : lookup) {
            // found a smaller number than x 
            // means x is not start of streak
            if (lookup.find(x-1) != lookup.end())
                continue;
            
            // x is start of streak
            int l = 1;
            while(lookup.find(++x) != lookup.end())
                l++;
            
            len = max(len, l);
        }

        return len;
    }
};
