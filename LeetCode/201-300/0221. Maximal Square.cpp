class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_len = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    int len = 0;
                    if (i > 0 and j > 0) {
                        len = min(dp[i - 1][j], dp[i][j - 1]);
                    }
                    dp[i][j] = len + (matrix[i - len][j - len] == '1'? 1 : 0);
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        return max_len * max_len;
    }
};
