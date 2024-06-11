class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == 'X') {
                    remove_ship(board, r, c);
                    count++;
                }
            }
        }
        return count;
    }

    void remove_ship(vector<vector<char>>& board, int row, int col) {
        for (int r = row; r < board.size() && board[r][col] == 'X'; r++) {
            board[r][col] = '.';
        }
        for (int c = col + 1; c < board[0].size() && board[row][c] == 'X'; c++) {
            board[row][c] = '.';
        }
    }
};
