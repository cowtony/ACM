class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i< board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    
    bool dfs(vector<vector<char>>& board, int row, int col, string word) {
        if (word.empty()) {
            return true;
        }
        if (word.front() != board[row][col]) {
            return false;
        } else if (word.length() == 1) {
            return true;
        }
        
        board[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            int r = row + kX.at(i);
            int c = col + kY.at(i);
            if (r < 0 or r >= board.size()) {
                continue;
            }
            if (c < 0 or c >= board[0].size()) {
                continue;
            }
            
            if (dfs(board, r, c, word.substr(1))) {
                return true;
            }
        }
        board[row][col] = word.front();
        return word.empty();
    }
};
