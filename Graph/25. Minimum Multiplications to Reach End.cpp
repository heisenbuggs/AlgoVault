#include <bits/stdc++.h>
using namespace std;

class Solution {
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        queue<pair<int, int>> q;
        q.push({0, start});  // {steps, node}

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second;

            for (auto it : arr) {
                long long newNode = (long long)node * it % 100000;
                if (steps + 1 < dist[newNode]) {
                    dist[newNode] = steps + 1;
                    if (newNode == end) return dist[newNode];
                    q.push({dist[newNode], newNode});
                }
            }
        }
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};