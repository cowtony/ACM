class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= A.size(); i++) {
            for (int w = 0; w <= m; w++) {
                if (w >= A.at(i - 1)) {
                    dp[i][w] = max(dp[i - 1][w - A.at(i - 1)] + V.at(i - 1), dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
                
            }
        }
        
        return dp[A.size()][m];
    }
};
