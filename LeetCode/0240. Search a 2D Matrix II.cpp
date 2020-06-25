class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int max_row = matrix.size() - 1, min_col = 0;
        while (max_row >= 0 and min_col < matrix[0].size()) {
            if (matrix[max_row][min_col] > target) {
                max_row--;
            } else if (matrix[max_row][min_col] < target) {
                min_col++;
            } else {
                return true;
            }
        }
        return false;
    }
};
