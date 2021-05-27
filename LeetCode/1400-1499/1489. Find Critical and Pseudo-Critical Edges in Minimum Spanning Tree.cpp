class UnionFind {
public:
    UnionFind(int n) : father(n) {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    
    int count;
private:
    vector<int> father;
};

int minimumSpanningTree(int n, vector<vector<int>>& edges, int skip = -1, int must_have = -1) {
    int weight = 0;
    UnionFind uf(n);
    
    if (must_have >= 0) {
        weight += edges[must_have][2];
        uf.connect(edges[must_have][0], edges[must_have][1]);
    }
    
    for (int i = 0; i < edges.size(); i++) {
        if (i == skip or i == must_have) {
            continue;
        }
        if (uf.root(edges[i][0]) != uf.root(edges[i][1])) {
            weight += edges[i][2];
            uf.connect(edges[i][0], edges[i][1]);
        }
    }
    if (uf.count != 1) {
        return INT_MAX;
    }
    return weight;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int weight = minimumSpanningTree(n, edges);
        
        vector<int> critical;
        vector<int> pseudo_critical;
        for (int i = 0; i < edges.size(); i++) {
            if (minimumSpanningTree(n, edges, i, -1) > weight) {
                critical.push_back(edges[i][3]);
            } else if (minimumSpanningTree(n, edges, -1, i) == weight) {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo_critical};
    }
};
