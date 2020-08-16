class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> DP(A.size(), vector<int>(A[0].size(), 0));

        for (int col = 0; col < A.size(); col++)
            DP[0][col] = A[0][col];

        for (int row = 1; row < A.size(); row++)
        {
            for (int col = 0; col < A.size(); col++)
            {
                if (col == 0)
                    DP[row][col] = min(DP[row - 1][col], DP[row - 1][col + 1]) + A[row][col];
                else if (col == A.size() - 1)
                    DP[row][col] = min(DP[row - 1][col - 1], DP[row - 1][col]) + A[row][col];
                else
                    DP[row][col] = min(DP[row - 1][col - 1], min(DP[row - 1][col], DP[row - 1][col + 1])) + A[row][col];
            }
        }

        int minimum = 999999;
        for (int col = 0; col < A.size(); col++)
            minimum = min(minimum, DP[A.size() - 1][col]);

        return minimum;
    }
};
