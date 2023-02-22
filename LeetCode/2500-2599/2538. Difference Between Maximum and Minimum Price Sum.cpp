class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<unordered_set<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0]].insert(edge[1]);
            tree[edge[1]].insert(edge[0]);
        }
        dfs(tree, price, 0, -1);
        return result;
    }

    int64_t result = 0;
    pair<int64_t, int64_t> dfs(const vector<unordered_set<int>>& tree, const vector<int>& price, int node, int prev) {
        int64_t max_sum = price[node];
        int64_t max_sum_no_leaf = 0;
        for (int child : tree[node]) {
            if (child == prev) {
                continue;
            }
            auto [sum, sum_no_leaf] = dfs(tree, price, child, node);
            
            result = max({result, sum + max_sum_no_leaf, sum_no_leaf + max_sum});

            max_sum = max(max_sum, sum + price[node]);
            max_sum_no_leaf = max(max_sum_no_leaf, sum_no_leaf + price[node]);
        }
        return {max_sum, max_sum_no_leaf};
    }
};
