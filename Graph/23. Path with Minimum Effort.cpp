#include <bits/stdc++.h>
using namespace std;

class Solution {
    int MinimumEffortPath(vector<vector<int>> &heights) {
        // {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>,
        greater<pair<int, pair<int, int>>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if (newEffort < dist[nr][nc]) {
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return 0; // unreachable
    }
};
