#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> topoSort(vector<vector<int>> adj, int v) {
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

        return topo;
    }

    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adj(k);
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(adj, k);
        string ans = "";
        for (auto it : topo) {
            ans = ans + char(it - 'a');
        }
        return ans;
    }
};