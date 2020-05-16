class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        if (A.empty()) {
            return 0;
        }
        vector<int> sum(A.size() + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            sum[i + 1] = sum[i] + A[i];
        }
        
        vector<vector<int>> dp(A.size(), vector<int>(A.size() + 1, 0));
        for (int len = 2; len <= A.size(); len++) {
            for (int i = 0; i + len <= A.size(); i++) {
                int min_scr = INT_MAX;
                for (int k = 1; k < len; k++) {
                    min_scr = min(min_scr, dp[i][k] + dp[i + k][len - k] + sum[i + len] - sum[i]);
                }
                dp[i][len] = min_scr;
            }
        }
        return dp[0][A.size()];
    }
};
