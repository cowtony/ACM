class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1;
        
        // Binary search by first column.
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (matrix[mid][0] > target) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        if (hi < 0) {
            return false;
        }
        
        int row = lo;
        lo = 0; hi = matrix[0].size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (matrix[row][mid] > target) {
                hi = mid - 1;
            } else if (matrix[row][mid] < target) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
