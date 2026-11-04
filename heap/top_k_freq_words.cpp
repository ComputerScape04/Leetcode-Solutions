class Solution {
public:
    struct compare {
        bool operator() (const pair<string, int>& a, const pair<string, int> &b)
        const {
            // if equal freq, choose lexicographical order
            if (a.second == b.second) {
                return a.first > b.first; // larger element is less important (smaller word goes first)
            }
            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;
        unordered_map<string, int> mp; // string --> freq
        vector<string> res;

        // store each string with freq in hash map
        for (string x : words)
            mp[x]++;
        
        // iterate through hashmap and store in priority queue
        for (const auto& [k, v] : mp)
            pq.push({k,v});

        // pop first k pairs
        while(k--) {
            pair<string, int> p = pq.top();
            res.push_back(p.first);
            pq.pop();
        }

        return res;
    }
};
