#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfsCheck(int node, vector<vector<int>> adj, vector<int> vis, vector<int> pathVis, vector<int> check) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

    vector<int> eventualSafeStates(vector<vector<int>> adj, int v) {
        vector<int> vis(v, 0), pathVis(v, 0), check(v, 0);
        vector<int> res;

        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }

        for(int i=0; i<v; i++) {
            if(check[i]) res.push_back(i);
        }
        return res;
    }
};