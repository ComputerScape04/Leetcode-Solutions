class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> newQueries;
        for (int i = 0; i < queries.size(); i++)
            newQueries.push_back({i, queries[i]}); // original index -> query time

        // sort the logs and queries on timestamp
        sort(logs.begin(), logs.end(), 
            [](const vector<int> &a, const vector<int> &b) {
                return a[1] < b[1];
            });
        sort(newQueries.begin(), newQueries.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            });
        
        int lSize = logs.size();
        int qSize = queries.size();

        // freq map for timestamp ; timestamp mapped to servers
        // timestamp -> count
        vector<int> server_count(n+1);
        vector<int> res(qSize);

        int left = 0, right = 0;
        int activeServers = 0;

        for (int i = 0; i < qSize; i++) {
            int result;
            pair<int, int> interval = {newQueries[i].second - x, newQueries[i].second};

            // move right pointer until it reaches end of the interval
            while(right < lSize && logs[right][1] <= interval.second) {
                if (server_count[logs[right][0]] == 0)
                    activeServers++;
                server_count[logs[right][0]]++;
                right++;
            }

            // move the left pointer till it reaches start of interval
            while(left < lSize && logs[left][1] < interval.first) {
                if (server_count[logs[left][0]] == 1)
                    activeServers--;
                server_count[logs[left][0]]--;
                left++;
            }

            result = n - activeServers;
            res[newQueries[i].first] = result;
        }

        return res;
    }
};
