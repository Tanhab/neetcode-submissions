#include <print>
class Solution {
   public:
    int n, m;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int dfs(int x, int y, vector<vector<int>>& grid) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || grid[x][y] == -1) return 0;
        //println("{} {} {}", x, y, grid[x][y]);
        grid[x][y] = -1;
        int c = 1;
        for (int i = 0; i < 4; i++) {
            c += dfs(x + dx[i], y + dy[i], grid);
        }
        return c;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    count = max(count, dfs(i, j, grid));
                }
            }
        }
        return count;
    }
};
