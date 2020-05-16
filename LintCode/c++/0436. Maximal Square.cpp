class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_len = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 or j == 0) {
                        dp[i][j] = matrix[i][j];
                    } else {
                        int len = min(dp[i - 1][j], dp[i][j - 1]);
                        dp[i][j] = len + matrix[i - len][j - len];
                    }
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len * max_len;
    }
};
