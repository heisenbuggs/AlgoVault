#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int r, int c, int m, int n) {
        vis[r][c] = 1;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(grid, vis, nr, nc, m, n);
            }
        }
    }

    int numIslands(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(grid, vis, i, j, m, n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};