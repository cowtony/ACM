class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i< board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word.front()) {
                    board[i][j] = 0;
                    if (dfs(board, i, j, word.substr(1))) {
                        return true;
                    }
                    board[i][j] = word.front();
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int row, int col, string word) {
        if (word.empty()) {
            return true;
        }
        if (row > 0 and board[row - 1][col] == word.front()) {
            board[row - 1][col] = 0;
            if (dfs(board, row - 1, col, word.substr(1))) {
                return true;
            }
            board[row - 1][col] = word.front();
        }
        if (row + 1 < board.size() and board[row + 1][col] == word.front()) {
            board[row + 1][col] = 0;
            if (dfs(board, row + 1, col, word.substr(1))) {
                return true;
            }
            board[row + 1][col] = word.front();
        }
        if (col > 0 and board[row][col - 1] == word.front()) {
            board[row][col - 1] = 0;
            if (dfs(board, row, col - 1, word.substr(1))) {
                return true;
            }
            board[row][col - 1] = word.front();
        }
        if (col + 1 < board[0].size() and board[row][col + 1] == word.front()) {
            board[row][col + 1] = 0;
            if (dfs(board, row, col + 1, word.substr(1))) {
                return true;
            }
            board[row][col + 1] = word.front();
        }
        return false;
    }
};
