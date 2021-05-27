// Binary Lifting
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) :dp(n, vector<int>(17, -1)) {
        for (int node = 0; node < n; node++) {
            dp[node][0] = parent[node];
        }
        for (int power = 1; power < maxPower; power++) {
            for (int node = 0; node < n; node++) {
                if (dp[node][power - 1] != -1) {
                    dp[node][power] = dp[dp[node][power - 1]][power - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) { 
        for (int power = maxPower, base = 1 << power; 
             power >= 0 and k > 0; 
             power--, base >>= 1) {
            
            if (k >= base) {
                if (node == -1 or power >= dp[node].size()) {
                    return -1;
                }
                node = dp[node][power];
                k -= base;
            }
        }
        return node;
    }
    
private:
    const int maxPower = 16;
    // dp[n][i] = dp[dp[n][i - 1]][i - 1]
    vector<vector<int>> dp; // dp[n][i] -> the 2^i th parent of node n.
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
