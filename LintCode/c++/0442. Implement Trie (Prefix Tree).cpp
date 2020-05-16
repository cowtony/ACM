// LeetCode 208: https://leetcode.com/problems/implement-trie-prefix-tree/
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
    Trie() {
        root = new TrieNode;
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
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
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                return false;
            }
            node = node->sons[c - 'a'];
        }
        return node->is_word;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
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
