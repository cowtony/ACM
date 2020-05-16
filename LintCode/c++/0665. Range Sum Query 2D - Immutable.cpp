class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        prefix_sum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                prefix_sum[r + 1][c + 1] = matrix[r][c] 
                                         + prefix_sum[r][c + 1]
                                         + prefix_sum[r + 1][c]
                                         - prefix_sum[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix_sum[row2 + 1][col2 + 1]
               - prefix_sum[row2 + 1][col1]
               - prefix_sum[row1][col2 + 1]
               + prefix_sum[row1][col1];
    }

private:
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
