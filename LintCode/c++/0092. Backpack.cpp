class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= A.size(); i++) {
            for (int v = 0; v <= m; v++) {
                if (v >= A.at(i - 1)) {
                    dp[i][v] = max(dp[i - 1][v - A.at(i - 1)] + A.at(i - 1), dp[i - 1][v]);
                } else {
                    dp[i][v] = dp[i - 1][v];
                }
                
            }
        }
        
        return dp[A.size()][m];
    }
};
