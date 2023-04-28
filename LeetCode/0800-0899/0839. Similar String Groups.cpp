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
    int numSimilarGroups(vector<string>& strs) {
        UnionFind uf(strs.size());

        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (similar(strs[i], strs[j])) {
                    uf.connect(i, j);
                }
            }
        }
        return uf.count;
    }

    bool similar(const string& s1, const string& s2) {
        int count = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (++count > 2) {
                    return false;
                }
            }
        }
        return true;
    }
};
