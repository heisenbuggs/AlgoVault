#include <bits/stdc++.h>
using namespace std;

class Solution {
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

    int numberOfProvinces(vector<vector<int>> adj, int n) {
        vector<int> vis(n, 0), dfs(n);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfsUtil(adj, vis, 0, dfs);
                cnt++;
            }
        }
        return cnt;
    }
};