class Solution {
public:
    vector<vector<int>> constructAdj(vector<int> &parent, int n){
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        return adj;
    }

    void computeNewParent(const vector<vector<int>>& adj, vector<int> lastSeen, int currNode, vector<int>& parent, const string& s) {
        if (lastSeen[s[currNode] - 'a'] != -1)
            parent[currNode] = lastSeen[s[currNode] - 'a'];

        lastSeen[s[currNode] - 'a'] = currNode; 

        for (int i = 0; i < adj[currNode].size(); i++)            
            computeNewParent(adj, lastSeen, adj[currNode][i], parent, s);
    }

    int subtreeSizes(vector<vector<int>>& adj, vector<int>& size, int currNode) {
        int totalSize = 1;
        for (int i = 0; i < adj[currNode].size(); i++) {
            totalSize += subtreeSizes(adj, size, adj[currNode][i]);
        }
        size[currNode] = totalSize;
        return totalSize;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        if (n == 1)
            return {1};

        vector<int> result(n);
        vector<vector<int>> adj = constructAdj(parent, n);
        vector<int> lastSeen(26, -1);

        computeNewParent(adj, lastSeen, 0, parent, s);

        adj = constructAdj(parent, n);

        subtreeSizes(adj, result, 0);

        return result;
    }
};
