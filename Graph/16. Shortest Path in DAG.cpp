#include <bits/stdc++.h>
using namespace std;

class Solution {
    void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<int> vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int n, int m, vector<vector<int>> edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        return dist;
    }
};