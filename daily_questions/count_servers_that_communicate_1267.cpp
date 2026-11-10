class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return 0;
        
        vector<int> rowCount(m);
        vector<int> colCount(n);
        int serverCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    rowCount[i]++;
                    colCount[j]++;
                    serverCount++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // check if that row or column has at least 2 servers
                if (grid[i][j] && (max(rowCount[i], colCount[j]) == 1)) {
                    serverCount--;
                }
            }
        }

        return serverCount;
    }
};
