class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> x = {-1, -1, -1, 0, 1, 1,  1,  0};
        vector<int> y = {-1,  0,  1, 1, 1, 0, -1, -1};
        
        for (int  i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = 0;
                for (int k = 0; k < x.size(); k++) {
                    int ii = i + x[k];
                    int jj = j + y[k];
                    if (ii >= 0 and ii < board.size() and jj >= 0 and jj < board[0].size()) {
                        count += board[ii][jj] & 1;
                    }
                }
                if (count < 2 or count > 3) {
                    board[i][j] += 0 << 1;
                } else if (count == 2) {
                    board[i][j] += board[i][j] << 1;
                } else if (count == 3) {
                    board[i][j] += 1 << 1;
                }
            }
        }
        
        for (int  i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
