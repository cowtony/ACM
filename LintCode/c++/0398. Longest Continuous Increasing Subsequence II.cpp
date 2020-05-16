class Solution {
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int max_len = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                max_len = max(max_len, dfs(matrix, dp, i, j));
            }
        }
        return max_len;
    }
    
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j) {
        if (dp[i][j] > 0) {
            return dp[i][j];
        }
        int max_len = 0;
        if (i > 0 and matrix[i][j] > matrix[i - 1][j]) {
            max_len = max(max_len, dfs(matrix, dp, i - 1, j));
        }
        if (i < matrix.size() - 1 and matrix[i][j] > matrix[i + 1][j]) {
            max_len = max(max_len, dfs(matrix, dp, i + 1, j));
        }
        if (j > 0 and matrix[i][j] > matrix[i][j - 1]) {
            max_len = max(max_len, dfs(matrix, dp, i, j - 1));
        }
        if (j < matrix[0].size() - 1 and matrix[i][j] > matrix[i][j + 1]) {
            max_len = max(max_len, dfs(matrix, dp, i, j + 1));
        }
        dp[i][j] = max_len + 1;
        return dp[i][j];
    }
};
