class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, i, j});
                }
            }
        }
        int mx = 0;
        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >=m)
                    continue;
                if(grid[xx][yy] == 2 || grid[xx][yy] == 0)
                    continue;
                grid[xx][yy] = 2;
                mx = max(mx, d +1);
                q.push({d+1, xx, yy}); 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return mx;
    }
};
