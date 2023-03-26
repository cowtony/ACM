class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        // Build the tree.
        vector<unordered_set<int>> tree(coins.size());
        for (const auto& edge : edges) {
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }
        
        // Iterativly remove all non-coin leaves.
        for (int i = 0; i < coins.size(); i++) {
            int node = i;
            while (tree[node].size() == 1 && coins[node] == 0) {
                int parent = *tree[node].begin();
                tree[parent].erase(node);
                tree[node].clear();
                node = parent;
            }
        }

        for (int i = 0; i < 2; ++i) {  // Remove all leaves twice.
            vector<int> leaves;
            for (int n = 0; n < coins.size(); ++n) {
                if (tree[n].size() == 1) {
                    leaves.push_back(n);
                }
            }
            for (int leaf : leaves) {
                if (!tree[leaf].empty()) {
                    int parent = *tree[leaf].begin();
                    tree[parent].erase(leaf);
                }
                tree[leaf].clear();
            }
        }

        int result = count_if(tree.begin(), tree.end(), [](const auto& children) {
            return !children.empty();
        });
        return max(0, result - 1) * 2;
    }
};
