#include <bits/stdc++.h>
using namespace std;

class DFSSolution {
    bool detect(vector<vector<int>> &adj, vector<int> &vis, int src, int parent) {
        vis[src] = 1;

        for (auto it : adj[src]) {
            if (!vis[it]) {
                if (detect(adj, vis, it, src) == true) return true;
            } else if (it != parent)
                return true;
        }
        return false;
    }

    bool isCycle(vector<vector<int>> &adj, int v) {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                if (detect(adj, vis, i, -1) == true) return true;
            }
        }
        return false;
    }
};

class BFSSolution {
    bool detect(vector<vector<int>> &adj, vector<int> &vis, int src) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                } else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>> &adj, int v) {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                if (detect(adj, vis, i) == true) return true;
            }
        }
        return false;
    }
};