class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= A.size(); i++) {
            for (int w = 0; w <= m; w++) {
                dp[i][w] = dp[i - 1][w];
                
                if (w >= A.at(i - 1)) {
                    dp[i][w] = max(dp[i][w], dp[i][w - A.at(i - 1)] + V.at(i - 1));
                }
            }
        }
        
        return dp[A.size()][m];
    }
};
