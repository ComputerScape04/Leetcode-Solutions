class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        if (n == 1 && m == 1)
            return {0};

        // store the servers in order of weight and insertion - [weight, index]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freePool;
        // [busy_duration, server_index]
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyPool;

        for (int i = 0; i < n; i++)
            freePool.push({servers[i], i});

        // store result
        vector<int> result(m);
        long long currTime = 0;

        // go through each task
        for (int i = 0; i < m; i++) {
            
            // task i is available at time i; forward time if needed
            currTime = max(currTime, (long long)i);

            // if there is no free server
            if (freePool.empty())
                currTime = busyPool.top().first;

            // check if there's a better server that is going to be free at time i
            while(!busyPool.empty() && busyPool.top().first <= currTime) {
                int idx = busyPool.top().second;
                pair<int, int> server = {servers[idx], idx};
                freePool.push(server);
                busyPool.pop();
            }
                
            // currently available free server
            // weight, index
            pair<int, int> server = freePool.top();
            busyPool.push({tasks[i] + currTime, server.second});
            freePool.pop();

            result[i] = server.second;
        }

        return result;
    }
};
