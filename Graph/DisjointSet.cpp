#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n+1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUParent(parent[node]); // path compression
    }

    void UnionByRank(int u, int v) {
        int ulpu = findUParent(u);
        int ulpv = findUParent(v);

        if (ulpu == ulpv) return;

        if (rank[ulpu] < rank[ulpv]) {
            parent[ulpu] = ulpv;
        }
        else if (rank[ulpu] > rank[ulpv]) {
            parent[ulpv] = ulpu;
        }
        else {
            parent[ulpv] = ulpu;
            rank[ulpu]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ulpu = findUParent(u);
        int ulpv = findUParent(v);

        if (ulpu == ulpv) return;

        if (rank[ulpu] < rank[ulpv]) {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};