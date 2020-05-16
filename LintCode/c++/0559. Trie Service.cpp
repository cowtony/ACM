/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and 
        // lintcode will print the tree struct.
        return root;
    }

    void insert(string& word, int frequency) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode;
            }
            node = node->children[c];
            auto it = node->top10.begin();
            for (; it != node->top10.end(); it++) {
                if (*it < frequency) {
                    break;
                }
            }
            node->top10.insert(it, frequency);
            if (node->top10.size() > 10) {
                node->top10.pop_back();
            }
        }
    }
};

