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

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        int res = minimumSpanningTree(N, connections);
        if (res == INT_MAX) {
            return -1;
        } else {
            return res;
        }
    }
    
    int minimumSpanningTree(int N, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int weight = 0;
        UnionFind uf(N);
        for (const auto& edge : edges) {
            if (uf.root(edge[0] - 1) != uf.root(edge[1] - 1)) {
                weight += edge[2];
                uf.connect(edge[0] - 1, edge[1] - 1);
            }
        }
        if (uf.count != 1) {
            return INT_MAX;
        }
        return weight;
    }
};
