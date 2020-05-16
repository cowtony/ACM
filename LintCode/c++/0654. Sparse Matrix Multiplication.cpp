class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        map<int, vector<pair<int, int>>> rowA; // Row, Col, Val
        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[0].size(); c++) {
                if (A[r][c] != 0) {
                    rowA[r].push_back(make_pair(c, A[r][c]));
                }
            }
        }
        map<int, map<int, int>> colB;  // Col, Row, Val
        for (int r = 0; r < B.size(); r++) {
            for (int c = 0; c < B[0].size(); c++) {
                if (B[r][c] != 0) {
                    colB[c][r] = B[r][c];
                }
            }
        }
        
        vector<vector<int>> ret(A.size(), vector<int>(B[0].size(), 0));
        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < B[0].size(); c++) {
                for (auto p : rowA[r]) {
                    ret[r][c] += p.second * colB[c][p.first];
                }
            }
        }
        return ret;
    }
};
