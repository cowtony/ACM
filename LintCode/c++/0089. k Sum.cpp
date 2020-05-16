class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        vector<vector<vector<int>>> dp(A.size() + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        for (int i = 0; i <= A.size(); i++) {
            dp[i][0][0] = 1;
        }
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= k and j <= i; j++) {
                for (int sum = 1; sum <= target; sum++) {
                    dp[i][j][sum] = dp[i - 1][j][sum];
                    if (sum >= A[i - 1]) {
                        dp[i][j][sum] += dp[i - 1][j - 1][sum - A[i - 1]];
                    }
                }
            }
        }
        
        return dp[A.size()][k][target];
    }
};
