class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        for (int r = 0; r < A.size(); r++) {
            setTo(A, r, 0);
            setTo(A, r, A[0].size() - 1);
        }
        for (int c = 0; c < A[0].size(); c++) {
            setTo(A, 0, c);
            setTo(A, A.size() - 1, c);
        }
        
        count = 0;
        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[0].size(); c++) {
                if (A[r][c] == 1) {
                    setTo(A, r, c);
                }
            }
        }
        return count;
    }
    
    int count = 0;
    const vector<int> kX{0, 0, 1, -1};
    const vector<int> kY{1, -1, 0, 0};
    void setTo(vector<vector<int>>& grid, int row, int col, int val = 0) {
        if (row < 0 or row >= grid.size() or col < 0 or col >= grid[0].size()) {
            return;
        }
        if (grid[row][col] == val) {
            return;
        }
        grid[row][col] = val;
        count++;
        for (int i = 0; i < 4; i++) {
            setTo(grid, row + kX.at(i), col + kY.at(i), val);
        }
    }
};
