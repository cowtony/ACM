class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int, set<int>> tree;
        for (vector<int> edge : edges) {
            tree[edge[0]].insert(edge[1]);
        }
        return dfs(tree, hasApple, 0);
    }
    
    int dfs(map<int, set<int>>& tree, const vector<bool>& hasApple, int node) {
        int cost = 0;
        if (tree.find(node) == tree.end()) {
            return 0;
        }
        for (int son : tree.at(node)) { 
            int c = dfs(tree, hasApple, son);
            if (c > 0 or hasApple[son]) {
                cost += 2 + c;
            }
        }
        return cost;
    }
};
