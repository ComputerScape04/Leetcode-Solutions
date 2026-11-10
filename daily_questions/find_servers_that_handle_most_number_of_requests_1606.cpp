class Solution {
public:
    struct compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        if (n == 1)
            return {0};

        vector<int> throughput(k); // stores throughput
        set<int> freeServers;
        vector<int> result;
        int maxThroughput = 0;

        // server number , task completion timestamp
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> busyServers;

        for(int i = 0; i < k; i++)
            freeServers.insert(i);

        int currTime = 0;
        for (int i = 0; i < n; i++) {
            currTime = arrival[i];
            int assignedServer = i % k;

            // check if any previously busy server is now free
            while(!busyServers.empty() && busyServers.top().second <= currTime) {
                freeServers.insert(busyServers.top().first);
                busyServers.pop();
            }

            if (freeServers.empty())
                continue;

            // auto it = lower_bound(freeServers.begin(), freeServers.end(), assignedServer);
            auto it = freeServers.lower_bound(assignedServer);
            if (it == freeServers.end())
                assignedServer = *freeServers.begin();
            else
                assignedServer = *it;

            // check if assignedServer is free
            // if (serverStatus[assignedServer]) {
                // ******** Leads to Quadratic ******** //
                // int temp = assignedServer;
                // assignedServer = (assignedServer + 1) % k;
                // while(serverStatus[assignedServer] && assignedServer != temp)
                //     assignedServer = (assignedServer + 1) % k;
                // if (assignedServer == temp)
                //     continue;
                // *********************************** //
            // }

            busyServers.push({assignedServer, arrival[i] + load[i]});
            throughput[assignedServer]++;
            maxThroughput = max(maxThroughput, throughput[assignedServer]);
            freeServers.erase(assignedServer);
        }

        for (int i = 0; i < k; i++) {
            // cout << "I: " << throughput[i] << endl;
            if (throughput[i] == maxThroughput)
                result.push_back(i);
        }

        return result;
    }
};
