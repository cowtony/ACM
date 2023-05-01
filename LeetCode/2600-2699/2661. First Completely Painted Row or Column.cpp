class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> mapping(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            mapping[arr[i]] = i;
        }
        
        for (auto& row : mat) {
            for (int& val : row) {
                val = mapping[val];
            }
        }
        int result = INT_MAX;
        for (const auto& row : mat) {
            result = min(result, *max_element(row.begin(), row.end()));
        }
        for (int col = 0; col < mat[0].size(); col++) {
            int max_val = -1;
            for (int row = 0; row < mat.size(); row++) {
                max_val = max(max_val, mat[row][col]);
            }
            result = min(result, max_val);
        }
        return result;
    }
};
