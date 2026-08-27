class Solution {
   public:
    int n, m;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '#' || grid[x][y] == '0') return;
        grid[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i], grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};
