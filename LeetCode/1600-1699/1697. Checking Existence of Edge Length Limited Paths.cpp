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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];  // Sort by limit
        });
        sort(edgeList.begin(), edgeList.end(), [](const auto& a, const auto& b) {
            return a[2] < b[2];  // Sort by distance
        });

        UnionFind uf(n);
        int i = 0;
        for (auto& query : queries) {
            while (i < edgeList.size() && edgeList[i][2] < query[2]) {
                uf.connect(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            query.push_back(uf.root(query[0]) == uf.root(query[1]));
        }

        sort(queries.begin(), queries.end(), [](const auto& a, const auto& b) {
            return a[3] < b[3];  // Sort by index
        });
        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            result[i] = queries[i][4];
        }
        return result;
    }
};
