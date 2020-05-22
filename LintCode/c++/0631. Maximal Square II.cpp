class Solution {
public:
    /**
     * @param matrix: a matrix of 0 an 1
     * @return: an integer
     */
    int maxSquare2(vector<vector<int>> &matrix) {
        // Create 3 DP matrix:
        vector<vector<int>> left(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> diagonal(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int max_size = 0;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    diagonal[r][c] = 0;
                    left[r][c] = right[r][c] = 1;
                    if (r > 0 and c > 0) {
                        left[r][c] = min(left[r - 1][c - 1], left[r][c - 1]) + 1;
                        right[r][c] = min(right[r - 1][c - 1], right[r - 1][c]) + 1;
                    }
                    
                } else {
                    left[r][c] = right[r][c] = 0;
                    diagonal[r][c] = 1;
                    if (r > 0 and c > 0) {
                        diagonal[r][c] = min({diagonal[r - 1][c - 1], left[r][c - 1], right[r - 1][c]}) + 1;
                    }
                }
                max_size = max(max_size, diagonal[r][c]);
            }
        }
        
        return max_size * max_size;
    }
};
