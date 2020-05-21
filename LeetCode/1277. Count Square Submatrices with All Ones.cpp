class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Use matrix directly as DP array, to store the maximum square size end at [r,c] corner.
        int count = 0;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (r > 0 and c > 0 and matrix[r][c] > 0) {
                    matrix[r][c] = min({matrix[r][c - 1], matrix[r - 1][c], matrix[r - 1][c - 1]}) + 1;
                }
                count += matrix[r][c];
            }
        }
        return count;
    }
};
