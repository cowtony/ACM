class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        vector<vector<int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = 0;
        vector<int> row_col = {matrix[0].size(), matrix.size() - 1};
        int rc = 0;
        
        int i = 0, j = -1;
        int count = 1;
        while (row_col[rc] > 0) {
            for (int k = 0; k < row_col[rc]; k++) {
                i += move[m][0];
                j += move[m][1];
                matrix[i][j] = count++;
            }
            row_col[rc]--;
            rc = 1 - rc; // flip RC index.
            m = (m + 1) % 4;
        }
        return matrix;
    }
};
