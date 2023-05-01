// Union Find with vector.
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind uf_alice(n);
        UnionFind uf_bob(n);

        int result = 0;
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (uf_alice.root(edge[1] - 1) == uf_alice.root(edge[2] - 1) && uf_bob.root(edge[1] - 1) == uf_bob.root(edge[2] - 1)) {
                    result++;
                } else {
                    uf_alice.connect(edge[1] - 1, edge[2] - 1);
                    uf_bob.connect(edge[1] - 1, edge[2] - 1);
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (uf_alice.root(edge[1] - 1) == uf_alice.root(edge[2] - 1)) {
                    result++;
                } else {
                    uf_alice.connect(edge[1] - 1, edge[2] - 1);
                }
            }
        }
        if (uf_alice.count > 1) {
            return -1;
        }

        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (uf_bob.root(edge[1] - 1) == uf_bob.root(edge[2] - 1)) {
                    result++;
                } else {
                    uf_bob.connect(edge[1] - 1, edge[2] - 1);
                }
            }
        }
        if (uf_bob.count > 1) {
            return -1;
        }
        return result;
    }
};
