#include <bits/stdc++.h>
using namespace std;

class Solution {
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        queue<pair<int, pair<int, int>>> q;
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        q.push({0, {src, 0}}); // {cost, {node, stops}}
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int cost = it.first;
            int node = it.second.first;
            int stops = it.second.second;

            if (stops > k) continue; // skip if stops exceed k

            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (cost + edgeWeight < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edgeWeight;
                    q.push({dist[adjNode], {adjNode, stops + 1}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
        