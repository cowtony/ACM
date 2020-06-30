class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : rows(n, 0), cols(n, 0) {
        size = n;
        diagnal = anti_diagnal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 2) {
            player = -1;
        }
        rows[row] += player;
        if (abs(rows[row]) == size) {
            return player == 1? 1 : 2;
        }
        cols[col] += player;
        if (abs(cols[col]) == size) {
            return player == 1? 1 : 2;
        }
        if (row == col) {
            diagnal += player;
            if (abs(diagnal) == size) {
                return player == 1? 1 : 2;
            }
        }
        if (row + col == size - 1) {
            anti_diagnal += player;
            if (abs(anti_diagnal) == size) {
                return player == 1? 1 : 2;
            }
        }
        return 0;
    }
    
private:
    vector<int> rows, cols;
    int diagnal, anti_diagnal;
    int size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
