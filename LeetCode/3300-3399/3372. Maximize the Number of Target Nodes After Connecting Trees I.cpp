class Solution {
public:
    typedef unordered_map<int, unordered_set<int>> Tree;

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        Tree tree1, tree2;
        for (const vector<int>& edge : edges1) {
            tree1[edge[0]].insert(edge[1]);
            tree1[edge[1]].insert(edge[0]);
        }

        for (const vector<int>& edge : edges2) {
            tree2[edge[0]].insert(edge[1]);
            tree2[edge[1]].insert(edge[0]);
        }

        int max_second_tree = 0;
        for (int root = 0; root <= edges2.size(); root++) {
            max_second_tree = max(max_second_tree, findMaxNodes(tree2, root, k - 1));
        }

        vector<int> result(edges1.size() + 1);
        for (int root = 0; root <= edges1.size(); root++) {
            result[root] = findMaxNodes(tree1, root, k) + max_second_tree;
        }
        return result;
    }

    int findMaxNodes(Tree& tree, int node, int k, int parent = -1) {
        if (k < 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        int result = 1;  // self
        for (int child : tree[node]) {
            if (child == parent) {
                continue;
            }
            result += findMaxNodes(tree, child, k - 1, node);
        }
        return result;
    }
};
