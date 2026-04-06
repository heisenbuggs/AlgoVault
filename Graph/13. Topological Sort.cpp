#include <bits/stdc++.h>
using namespace std;

class DFSSolution {
    void dfs(int node, vector<int> vis, stack<int> &st, vector<vector<int>> adj) {
        vis[node] = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) dfs(it, vis, st, adj);
        }
        st.push(node);
    }

    vector<int> topoSort(vector<vector<int>> adj, int v) {
        vector<int> vis(v, 0);
        stack<int> st;
        for(int i=0; i<v; i++) {
            if(!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class BFSSolution {
    vector<int> isCyclic(vector<vector<int>> adj, int v) {
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

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                ind[it]--;
                if (ind[it] == 0) q.push(it);
            }
        }
        return topo;
    }
};