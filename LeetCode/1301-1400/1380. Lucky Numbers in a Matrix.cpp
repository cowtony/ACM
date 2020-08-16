class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int> min_row;
        set<int> max_col;
        for (int i = 0; i < matrix.size(); i++) {
            int minimum = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                minimum = min(minimum, matrix[i][j]);
            }
            min_row.insert(minimum);
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            int maximum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                maximum = max(maximum, matrix[i][j]);
            }
            max_col.insert(maximum);
        }
        vector<int> ret;
        for (int m : min_row) {
            if (max_col.find(m) != max_col.end()) {
                ret.push_back(m);
            }
        }
        return ret;
    }
};
