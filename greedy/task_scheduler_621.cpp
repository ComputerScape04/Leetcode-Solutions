class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskSize = tasks.size();
        if (n == 0)
            return taskSize;

        unordered_map<char, int> mp;
        priority_queue<int> pq;
        queue<pair<int, int>> q; // val -> time

        for (char c : tasks)
            mp[c]++;

        // store them in the max heap
        for (const auto& [k, v] : mp)
            pq.push(v);

        int currTime = 1;

        while(!pq.empty() || !q.empty()) {
            currTime++;

            if (!pq.empty()) {
                int val = pq.top() - 1;
                pq.pop();
                if (val > 0)
                    q.push({val, currTime + n});
            }

            // check if any val becomes free to use at currTime
            while(!q.empty() && q.front().second <= currTime) {
                pair<int, int> p = q.front();
                q.pop();
                pq.push(p.first);
            }

            // if pq is empty then advance time
            if (pq.empty() && !q.empty()) {
                currTime = q.front().second - 1;
            }
        }

        return currTime-1;
    }
};
