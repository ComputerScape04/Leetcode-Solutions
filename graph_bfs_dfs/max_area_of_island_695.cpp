class Solution {
public:
    int islandCount(vector<vector<int>> &grid, int r, int c, int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = -1;

        return 1 + islandCount(grid, r, c, i-1, j) + islandCount(grid, r, c, i+1, j)
            + islandCount(grid, r, c, i, j-1) + islandCount(grid, r, c, i, j+1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int len = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    len = max(len, islandCount(grid, r, c, i, j));
            }
        }

        return len;
    }
};
