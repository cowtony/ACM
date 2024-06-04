class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int N = edges.size() + 1;
        vector<vector<pair<int, int>>> tree(N);

        for (const auto& edge : edges) {
            tree[edge[0]].emplace_back(edge[1], edge[2]);
            tree[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<int> result(N);
        for (int root = 0; root < N; root++) {
            result[root] = dfs(tree, signalSpeed, root).second;
        }
        return result;
    }

    pair<int, int> dfs(const vector<vector<pair<int, int>>>& tree, int signalSpeed, int node, int parent = -1, int dist = 0) {
        int node_count = dist > 0 && dist % signalSpeed == 0? 1 : 0;
        int pair_count = 0;
        for (const auto& [child, weight] : tree[node]) {
            if (child == parent) {
                continue;
            }
            auto [n, p] = dfs(tree, signalSpeed, child, node, dist + weight);
            pair_count += node_count * n;
            node_count += n;
        }
        return {node_count, pair_count};
    }
};
