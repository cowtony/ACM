#include "union_find.h"

// Kruskal Algorithm. O(ElogE)
int minimumSpanningTree(vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    int weight = 0;
    UnionFind<int> uf;
    for (const auto& edge : edges) {
        if (uf.root(edge[0]) != uf.root(edge[1])) {
            weight += edge[2];
            uf.connect(edge[0], edge[1]);
        }
    }
    if (uf.roots.size() != 1) {
        return INT_MAX;
    }
    return weight;
}
