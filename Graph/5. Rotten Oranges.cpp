#include <bits/stdc++.h>
using namespace std;

class Solution {
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // {t, {r, c}}
        queue<pair<int, pair<int, int>>> q;
        int cnt = 0, ans = 0;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    cnt++;
                } else if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            ans = max(ans, t);
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1) {
                    cnt--;
                    grid[nr][nc] = 2;
                    q.push({t + 1, {nr, nc}});
                }
            }
        }
        return cnt == 0 ? ans : -1;
    }
};