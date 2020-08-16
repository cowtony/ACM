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
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                node->sons[c - 'a'] = new TrieNode;
            }
            node = node->sons[c - 'a'];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    TrieNode* root;
    
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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
