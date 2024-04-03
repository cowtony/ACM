class Solution {
public:
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
    
    bool dfs(vector<vector<char>>& board, int row, int col, string& word) {
        if (word.back() != board[row][col]) {
            return false;
        } 

        char last_letter = board[row][col];
        word.pop_back();
        board[row][col] = 0;

        if (word.empty()) {
            return true;
        }
        
        static const vector<int> kMove = {0, 1, 0, -1, 0};
        for (int i = 0; i < 4; i++) {
            int r = row + kMove.at(i);
            int c = col + kMove.at(i + 1);
            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
                continue;
            }
            if (dfs(board, r, c, word)) {
                return true;
            }
        }
        word.push_back(last_letter);
        board[row][col] = last_letter;
        return word.empty();
    }
};
