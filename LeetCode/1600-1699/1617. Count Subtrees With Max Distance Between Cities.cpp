class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(n);
        for (const auto& edge : edges) {
            tree[edge[0] - 1].insert(edge[1] - 1);
            tree[edge[1] - 1].insert(edge[0] - 1);
        }

        vector<int> result(n - 1, 0);
        for (int state = (1 << n) - 1; state > 0; --state) {
            int root = 0;
            while ((state & (1 << root)) == 0) {  // Pick a root
                root++;
            }
            int visited = state & ~(1 << root);
            int diameter = 0;
            getDepth(tree, visited, diameter, root);
            if (visited == 0 && diameter > 0) {  // all nodes visited, valid subset
                result[diameter - 1]++;
            }
        }
        return result;
    }

    int getDepth(const vector<unordered_set<int>>& tree, int& visited, int& diameter, int node) {
        int a = 0, b = 0;
        for (int next : tree.at(node)) {
            if ((visited & (1 << next)) == 0) {
                continue;
            }
            visited &= ~(1 << next);  // set to 0.
            int d = getDepth(tree, visited, diameter, next);
            if (d > a) {
                b = a;
                a = d;
            } else if (d > b) {
                b = d;
            }
        }
        diameter = max(diameter, a + b);
        return a + 1;
    }
};
