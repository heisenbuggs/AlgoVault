#include <bits/stdc++.h>
using namespace std;

class Solution {
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && dis + 1 < dist[nr][nc]) {
                    dist[nr][nc] = 1 + dis;
                    if (nr == destination.first && nc == destination.second) return dis + 1;
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }
        return -1;
    }
};
