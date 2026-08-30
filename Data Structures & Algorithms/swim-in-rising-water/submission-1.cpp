class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const int inf = INT_MAX / 4;
        vector<vector<int>> dist(n, vector<int>(n, inf));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        dist[0][0] = grid[0][0];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty()) {
            auto [w, x, y] = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
                if (max(w, grid[xx][yy]) < dist[xx][yy]) {
                    pq.push({max(w, grid[xx][yy]), xx, yy});
                    dist[xx][yy] = max(w, grid[xx][yy]);
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};
