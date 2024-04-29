class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int diff = -int(mat.size()) + 1; diff < int(mat[0].size()); diff++) {  // For every diagnal
            vector<int> nums;
            for (int r = 0, c = diff; r < mat.size(); r++, c++) {
                if (c < 0 || c >= mat[0].size()) {
                    continue;
                }
                nums.push_back(mat[r][c]);
            }
            sort(nums.begin(), nums.end());

            int i = 0;
            for (int r = 0, c = diff; r < mat.size(); r++, c++) {
                if (c < 0 || c >= mat[0].size()) {
                    continue;
                }
                mat[r][c] = nums[i++];
            }
        }
        return mat;
    }
};
