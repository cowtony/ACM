class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }
        for (int i = 0; i < board[0].size(); i++) {
            dfs(board, 0, i);
            dfs(board, board.size() - 1, i);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>> &board, int r, int c) {
        if (r < 0 or r >= board.size()) {
            return;
        }
        if (c < 0 or c >= board[0].size()) {
            return;
        }
        if (board.at(r).at(c) == 'X' or board.at(r).at(c) == '1') {
            return;
        } 
        
        board[r][c] = '1';
        static const vector<int> kX = {0, 0, 1, -1};
        static const vector<int> kY = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            dfs(board, r + kX.at(i), c + kY.at(i));
        }
    }
};
