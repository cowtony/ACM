class UnionFind {
  public:
    UnionFind(int n) : father_(n), size_(n, 1) {
        for (int i = 0; i < father_.size(); ++i) {
            father_[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        if (a > b) { swap(a, b); }
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father_[rb] = ra;
            size_[ra] += size_[rb];
            // TODO: process `data` here.
            count--;
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

  private:
    vector<int> father_;
    vector<int> size_; // Store count of the component.
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            uf.connect(edge[0], edge[1]);
        }

        long long result = 0;
        for (const auto& [root, nodes] : uf.getComponents()) {
            n -= nodes.size();
            result += nodes.size() * n;
        }

        return result;
    }
};
