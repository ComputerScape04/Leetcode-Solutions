class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        const {
            return a.second < b.second; // smaller is less important
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Heap Solution
        priority_queue<pair<int, int>, vector<pair<int,int>>, compare> pq;
        unordered_map<int, int> mp; // val --> freq
        vector<int> res;

        for (int x : nums) 
            mp[x]++;

        // insert [k,v] into max heap
        for (const auto& [k, v] : mp) {
            pair<int, int> p = {k,v};
            pq.push(p);
        }

        while(k--) {
            pair<int, int> p = pq.top();
            res.push_back(p.first);
            pq.pop();
        }

        return res;
    }
};
