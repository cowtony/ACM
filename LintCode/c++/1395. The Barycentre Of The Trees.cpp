class Solution {
public:
    /**
     * @param x: The vertexes of the edges
     * @param y: The vertexes of the edges
     * @return: Return the index of barycentre
     */
    int getBarycentre(vector<int> &x, vector<int> &y) {
        // Build tree.
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < x.size(); i++) {
            tree[x[i]].push_back(y[i]);
            tree[y[i]].push_back(x[i]);
        }
        
        node_count = x.size() + 1;
        dfs(tree, 1, -1);
        return ansNode;
    }
    
    // DFS + memorize (dp).
    int node_count;
    int ansNode = 0;
    int ansSize = INT_MAX;
    map<int, int> dp; // Key: node, Val: number of nodes from that subtree. (this is base on 1 as root)
    void dfs(unordered_map<int, vector<int>>& tree, int node, int father) {
        dp[node] = 1; // Count self as 1.
        int maxSubtree = 0;
        for (int son : tree[node]) {
            if (son == father) {
                continue;
            }
            dfs(tree, son, node);  // Get dp[son].
            dp[node] += dp[son];  // Add subtree's node size.
            maxSubtree = max(maxSubtree, dp[son]);
        }
        maxSubtree = max(maxSubtree, node_count - dp[node]); // Also consider the father as a branch.
        
        if (maxSubtree < ansSize or (maxSubtree == ansSize and node < ansNode)) {
            ansNode = node;
            ansSize = maxSubtree;
        }
    }
};
