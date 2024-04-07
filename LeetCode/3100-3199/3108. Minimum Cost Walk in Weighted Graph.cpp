class UnionFind {
  public:
    UnionFind(int n) : father_(n), size_(n, 1), weight(n, -1) {
        for (int i = 0; i < father_.size(); ++i) {
            father_[i] = i;
        }
        count = n;
    }
    void connect(int a, int b, int w) {
        if (a > b) { swap(a, b); }
        int ra = root(a);
        int rb = root(b);
        weight[ra] &= w;
        if (ra != rb) {
            father_[rb] = ra;
            size_[ra] += size_[rb];
            count--;
            weight[ra] &= weight[rb];
        }
    }
    
    int root(int x) {
        if (father_[x] == x) { return x; } 
        else { return father_[x] = root(father_[x]); }
    }
    int getSize(int x) {
        return size_[root(x)];
    }
    unordered_map<int, vector<int>> getComponents() {
        unordered_map<int, vector<int>> result;
        for (int i = 0; i < father_.size(); i++) {
            result[root(i)].push_back(i);
        }
        return result;
    }

    int count;        // Number of distinct component.
    vector<int> weight;
    vector<int> father_;
    vector<int> size_; // Store count of the component.
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.connect(edge[0], edge[1], edge[2]);
        }
        
        vector<int> result;
        result.reserve(query.size());
        for (const auto& q : query) {
            if (q[0] == q[1]) {
                result.push_back(0);
            } else if (uf.root(q[0]) == uf.root(q[1])) {
                result.push_back(uf.weight[uf.root(q[0])]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};
