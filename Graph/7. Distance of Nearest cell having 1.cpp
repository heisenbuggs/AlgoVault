#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> nearestCell(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)), dist(m, vector<int>(n, 0));
        // {{r, c}, d}
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dist[r][c] = d;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return dist;
    }
};