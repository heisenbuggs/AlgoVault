#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<pair<int, int>> prequisites, int v) {
        vector<vector<int>> adj(v);
        for (auto it : prequisites) {
            adj[it.first].push_back(it.second);
        }

        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topo.size() == v;
    }
};