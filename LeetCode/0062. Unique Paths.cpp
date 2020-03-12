class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> DP(m, vector<int>(n, 1));
        for (int row = 1; row < m; row++)
            for (int col = 1; col < n; col++)
            {
                DP[row][col] = DP[row - 1][col] + DP[row][col - 1];
            }
        return DP[m - 1][n - 1];
    }
};
