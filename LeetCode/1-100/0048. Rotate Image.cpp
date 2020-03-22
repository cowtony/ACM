class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flipLeftRight(matrix);
        
    }
private:
    void flipLeftRight(vector<vector<int>>& matrix) {
        for (vector<int> &row : matrix)
            reverse(row.begin(), row.end());
    }
    
    void flipUpDown(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
    }
    
    void transpose(vector<vector<int>>& matrix) {
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row + 1; col < matrix.size(); col ++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
