class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        vector<vector<int>> dp(A.length() + 1, vector<int>(B.length() + 1, 0));
        
        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[A.length()][B.length()];
    }
};
