#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bellmanFord(int v, vector<vector<int>> &edges, int s) {
        vector<int> dist(v, INT_MAX);
        dist[s] = 0;
        for (int i = 0; i < v; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};