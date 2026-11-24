class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;

        int r = image.size();
        int c = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            pair<int, int> p = q.front(); // sr, sc
            q.pop();

            // check if adjacent nodes are the same color and if they're visited or not
            if (p.first > 0 && image[p.first-1][p.second] != color && image[p.first-1][p.second] == image[p.first][p.second])
                q.push({p.first-1, p.second});
            if (p.first < r-1 && image[p.first+1][p.second] != color && image[p.first+1][p.second] == image[p.first][p.second])
                q.push({p.first+1, p.second});
            if (p.second > 0 && image[p.first][p.second-1] != color && image[p.first][p.second-1] == image[p.first][p.second])
                q.push({p.first, p.second-1});
            if (p.second < c-1 && image[p.first][p.second+1] != color && image[p.first][p.second+1] == image[p.first][p.second])
                q.push({p.first, p.second+1});   

            image[p.first][p.second] = color;
        }
        
        return image;
    }
};
