// LeetCode 212: https://leetcode.com/problems/word-search-ii/
struct TrieNode {
    unordered_map<char, TrieNode*> sons;
    string word;
};
    
class Trie {
public:
    Trie() {
        root = new TrieNode;
    }
    
    TrieNode* root;
    
    void addWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons[c];
        }
        node->word = word;
    }
};

class Solution {
    
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        Trie trie;
        for (const string& word : words) {
            trie.addWord(word);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, trie.root, i, j);
            }
        }
        vector<string> ret;
        for (const string& word : matches) {
            ret.emplace_back(word);
        }
        return ret;
    }
    
private:
    set<string> matches;
    void dfs(vector<vector<char>>& board, TrieNode* parent_node, int i, int j) {
        if (parent_node->sons.find(board[i][j]) == parent_node->sons.end()) {
            return;
        }
        TrieNode* node = parent_node->sons.at(board[i][j]);
        if (!node->word.empty()) {
            matches.insert(node->word);
        }
        
        board[i][j] -= 'a';
        vector<int> x = {0, 1, 0, -1};
        vector<int> y = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int r = i + x[k];
            int c = j + y[k];
            if (validMove(board, r, c)) {
                dfs(board, node, r, c);
            }
        }
        board[i][j] += 'a';
    }
    
    bool validMove(vector<vector<char>>& board, int i, int j) const {
        if (i < 0 or i >= board.size()) {
            return false;
        }
        if (j < 0 or j >= board[0].size()) {
            return false;
        }
        return board[i][j] >= 'a';
    }
};
