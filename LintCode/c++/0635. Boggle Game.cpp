
struct TrieNode {
    unordered_map<char, TrieNode*> sons;
    bool is_word = false;
    
    void insert(const string& word) {
        TrieNode* node = this;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons.at(c);
        }
        node->is_word = true;
    }
};

class Solution {
public:
    /*
     * @param board: a list of lists of character
     * @param words: a list of string
     * @return: an integer
     */
    // a b c d e-f-g
    //
    // h u y u y w-w
    // |            
    // g h i h j u i
    //             |
    // w-u-i i-u-w w
    // {"efg","gh","iuw","ww","iw"}
    // {"efg","defi","gh","iuw","ww","iw","ghih","dasf","aaa"}
    int boggleGame(vector<vector<char>> &board, vector<string> &words) {
        trie = new TrieNode;
        for (const string& word : words) {
            trie->insert(word);
        }
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        dfs(board, visited, 0, 0);
        return max_count;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        for (int r = row; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (r == row and c < col) {
                    continue;
                }
                searchWord(board, visited, trie, r, c, r, c);
            }
        }
    }
    
    int count = 0;
    int max_count = 0;
    TrieNode* trie;

    void searchWord(vector<vector<char>>& board, 
                    vector<vector<bool>>& visited, 
                    TrieNode* node, int row, int col, 
                    int start_row, int start_col) {
        if (row < 0 or row >= board.size() or col < 0 or col >= board[0].size()) {
            return;
        }
        if (visited[row][col]) {
            return;
        }
        if (node->sons.find(board[row][col]) == node->sons.end()) {
            return;
        }
        node = node->sons.at(board[row][col]);
        
        visited[row][col] = true;
        if (node->is_word) {
            count++;
            max_count = max(max_count, count);
            dfs(board, visited, start_row, start_col);
            count--;
            visited[row][col] = false;
            return; // Early break. Another word with this Suffix would never be used.
        }
        
        static const vector<int> kX = {0, 0, 1, -1};
        static const vector<int> kY = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            searchWord(board, visited, node, row + kX.at(i), col + kY.at(i), start_row, start_col);
        }
        visited[row][col] = false;
    }
};
