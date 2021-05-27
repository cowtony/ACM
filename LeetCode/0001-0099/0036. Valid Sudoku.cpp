class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> squares(9);
        for (int i = 0; i < 9; i++) {
            set<char> row, col; // Check for 9 rows and 9 columns.
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row.find(board[i][j]) != row.end()) {
                        return false;
                    } else {
                        row.insert(board[i][j]);
                    }
                    
                    // Square check:
                    set<int>& square = squares[i / 3 * 3 + j / 3];
                    if (square.find(board[i][j]) != square.end()) {
                        return false;
                    } else {
                        square.insert(board[i][j]);
                    }
                }
                if (board[j][i] != '.') {
                    if (col.find(board[j][i]) != col.end()) {
                        return false;
                    } else {
                        col.insert(board[j][i]);
                    }
                }
            }
        }
        
        return true;
    }
};
