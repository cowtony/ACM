struct TrieNode {
    TrieNode() {
        sons = vector<TrieNode*>(26, nullptr);
        is_word = false;
    }
    vector<TrieNode*> sons;
    bool is_word;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                node->sons[c - 'a'] = new TrieNode;
            }
            node = node->sons[c - 'a'];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                return false;
            }
            node = node->sons[c - 'a'];
        }
        return node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->sons[c - 'a']) {
                return false;
            }
            node = node->sons[c - 'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
