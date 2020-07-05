class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        vector<vector<int>> prefix{mat};
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                if (mat[r][c] == 1 and c > 0) {
                    prefix[r][c] += prefix[r][c - 1];
                }
            }
        }
        
        int res = 0;
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                int min_left = INT_MAX;
                for (int i = r; i >= 0 and min_left > 0; i--) {
                    min_left = min(min_left, prefix[i][c]);
                    res += min_left;
                }
            }
        }
        return res;
    }
};
