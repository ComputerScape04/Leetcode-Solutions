class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int freshOranges = 0;   
        int minutes = 0;
        queue<pair<int, int>> rottenOranges;

        // push all the rotten oranges into the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2)
                    rottenOranges.push({i,j});
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if (freshOranges == 0)
            return 0;

        // run multi-source bfs
        while(!rottenOranges.empty() && freshOranges) {
            int n = rottenOranges.size();

            // for each rotten orange
            for (int i = 0; i < n; i++) {
                auto [x,y] = rottenOranges.front();
                rottenOranges.pop();

                if (x > 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    freshOranges--;
                    rottenOranges.push({x-1, y});
                }
                if (x < r-1 && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    freshOranges--;
                    rottenOranges.push({x+1, y});
                }
                if (y > 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    freshOranges--;
                    rottenOranges.push({x, y-1});
                }
                if (y < c-1 && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    freshOranges--;
                    rottenOranges.push({x, y+1});
                }
            }

            minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};
