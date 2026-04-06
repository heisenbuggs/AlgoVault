#include <bits/stdc++.h>
using namespace std;

vector<int> bfsGraph(vector<vector<int>> adj, int n) {
    vector<int> vis(n, 0), bfs;
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                q.push(it);
            }
        }
    }
    return bfs;
}

void dfsUtil(vector<vector<int>> &adj, vector<int> &vis, int src, vector<int> &dfs) {
    dfs.push_back(src);
    vis[src] = 1;

    for (auto it : adj[src]) {
        if (!vis[it]) {
            dfsUtil(adj, vis, it, dfs);
        }
    }
    return;
}

vector<int> dfsGraph(vector<vector<int>> adj, int n) {
    vector<int> vis(n, 0), dfs(n);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfsUtil(adj, vis, 0, dfs);
        }
    }
}