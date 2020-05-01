class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix.empty()? 0 : matrix[0].size();
        prefix_sum = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
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
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
