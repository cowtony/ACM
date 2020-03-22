// LeetCode 211: https://leetcode.com/problems/add-and-search-word-data-structure-design/
class WordDictionary {
    struct TrieNode {
        TrieNode() {
            sons = vector<TrieNode*>(26, nullptr);
            is_word = false;
        }
        vector<TrieNode*> sons;
        bool is_word;
    };
    
public:
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                node->sons[c - 'a'] = new TrieNode;
            }
            node = node->sons[c - 'a'];
        }
        node->is_word = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        return dfs(word, 0, root);
    }
    
private:
    TrieNode* root = new TrieNode;
    
    bool dfs(string &word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->is_word;
        }
        if (word[index] == '.') {
            for (char t = 'a'; t <= 'z'; t++) {
                if (node->sons[t - 'a'] and dfs(word, index + 1, node->sons[t - 'a'])) {
                    return true;
                }
            }
            return false;
        } else if (!node->sons[word[index] - 'a']) {
            return false;
        }
        return dfs(word, index + 1, node->sons[word[index] - 'a']);
    }
};
