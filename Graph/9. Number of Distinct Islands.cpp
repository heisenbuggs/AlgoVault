#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int r0, int c0) {
        vis[r][c] = 1;
        vec.push_back({r - r0, c - c0});

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc]) {
                dfs(nr, nc, grid, vis, vec, r0, c0);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};