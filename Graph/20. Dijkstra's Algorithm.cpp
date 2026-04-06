#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Dijkstra's using Priority Queue
    vector<int> dijkstra(vector<vector<int>> adj[], int v, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(v, 1e9);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int edW = it[1];
                int adjNode = it[0];

                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

class Solution {
    // Dikjstra's using Set
    vector<int> dijkstra(vector<vector<int>> adj[], int v, int src) {
        set<pair<int, int>> st;
        vector<int> dist(v, 1e9);

        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];

                if (dis + edW < dist[adjNode]) {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
