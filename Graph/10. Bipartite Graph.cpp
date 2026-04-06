#include <bits/stdc++.h>
using namespace std;

class BFSSolution {
    bool bipartite(vector<vector<int>> &adj, int v) {
        vector<int> color(v, -1);
        queue<int> q;
        q.push(0);
        color[0] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (color[it] != -1) {
                    color[it] = !color[node];
                    q.push(it);
                } 
                else if (color[node] == color[it]) {
                    return false;
                }
            }
        }
        return true;
    }
};

class DFSSolution {
    bool dfs(vector<vector<int>> &adj, int v, vector<int> &color, int col, int src) {
        color[src] = col;

        for (auto it : adj[src]) {
            if (color[it] != -1) {
                if (dfs(adj, v, color, col, it) == false) return false;
            } 
            else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool bipartite(vector<vector<int>> &adj, int v) {
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1)
                if (dfs(adj, v, color, 0, i) == false) return false;
        }
        return true;
    }
};