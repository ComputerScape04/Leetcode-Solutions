/*
dfss` from first "1"
when it ends, increment island counter by 1
start the next bfs at next occurance at 1

mark nodes visited by modifying them to #

*/

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c, int i, int j) {
        if ((i >= 0 && i < r) && (j >= 0 && j < c) && grid[i][j] == '1')
            grid[i][j] = '#';

        if (i > 0 && grid[i-1][j] == '1') bfs(grid, r, c, i-1, j);
        if (i < r-1 && grid[i+1][j] == '1') bfs(grid, r, c, i+1, j);
        if (j > 0 && grid[i][j-1] == '1') bfs(grid, r, c, i, j-1);
        if (j < c-1 && grid[i][j+1] == '1') bfs(grid, r, c, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0;

        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, r, c, i, j);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
