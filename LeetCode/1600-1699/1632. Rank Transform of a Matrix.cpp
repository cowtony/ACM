template <class Node = int>
class UnionFind {
  public:
    // The connect function will add new element automatically.
    Node connect(const Node& a, const Node& b) {
        Node ra = root(a);
        Node rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            for (const Node& n : component[ra]) {
                component[rb].insert(n);
            }
            component.erase(ra);
        }
        return rb;
    }
    
    // Find root with route compress.
    Node root(const Node& a) {
        if (father.find(a) == father.end()) { // New node seen.
            father[a] = a;
            component[a].insert(a);
        }
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }

    int getSize(const Node& a) { return component[root(a)].size(); }
    const unordered_set<Node>& getNodesOf(const Node& a) { return component[root(a)]; }

    unordered_map<Node, Node> father;
    unordered_map<Node, unordered_set<Node>> component;  // Store all nodes connected as a component.
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int kRow = matrix.size(), kCol = matrix[0].size();

        map<int, vector<pair<int, int>>> group_by_num;
        for (int r = 0; r < kRow; r++) {
            for (int c = 0; c < kCol; c++) {
                group_by_num[matrix[r][c]].push_back({r, c});
            }
        }

        vector<int> max_rank(kRow + kCol, 0);  // First kRow element means for each row, then for each col.
        for (const auto& [val, points] : group_by_num) {
            UnionFind uf;
            for (const auto& [r, c] : points) {
                uf.connect(r, kRow + c);  // Connect row r and col c.
            }
            for (const auto& [_, nodes] : uf.component) {
                int rank = 0;
                for (int node : nodes) {
                    rank = max(rank, max_rank[node]);
                }
                for (int node : nodes) {
                    max_rank[node] = rank + 1;
                }
            }
            for (const auto& [r, c] : points) {
                matrix[r][c] = max_rank[r];
            }
        }
        return matrix;
    }
};
