#include <bits/stdc++.h>
using namespace std;

class DFSSolution {
    bool dfsCheck(int node, vector<vector<int>> adj, vector<int> vis, vector<int> pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(vector<vector<int>> adj, int v) {
        vector<int> vis(v, 0), pathVis(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
    }
};

class BFSSolution {
    bool isCyclic(vector<vector<int>> adj, int v) {
        vector<int> ind(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                ind[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node]) {
                ind[it]--;
                if (ind[it] == 0) q.push(it);
            }
        }

        return cnt == v ? false : true;
    }
};