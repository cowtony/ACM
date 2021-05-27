class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // 1
        // 1 1
        // 1 2 1
        // 1 3 3 1
        vector<int> res;
        for (int row = 0; row <= rowIndex; row++) {
            res.push_back(1);
            for (int col = row - 1; col > 0; col--) {
                res[col] += res[col - 1];
            }
        }
        return res;
    }
};
