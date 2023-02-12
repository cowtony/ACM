class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        if (roads.empty()) {
            return 0;
        }

        unordered_map<int, vector<int>> tree;
        for (const auto& road : roads) {
            tree[road[0]].push_back(road[1]);
            tree[road[1]].push_back(road[0]);
        }

        return countChildren(tree, 0, -1, seats).second;
    }

    pair<int64_t, int64_t> countChildren(const unordered_map<int, vector<int>>& tree, int node, int parent, int seats) {
        int64_t count = 1, fuel = 0;
        for (int child : tree.at(node)) {
            if (child != parent) {
                auto [c, f] = countChildren(tree, child, node, seats);
                count += c;
                fuel += f + (c - 1) / seats + 1;
            }
        }
        return {count, fuel};
    }
};
