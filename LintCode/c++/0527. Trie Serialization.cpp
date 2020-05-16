/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        dfs(root);
        return words;
    }
    
    string words;
    void dfs(TrieNode* root, string word = "") {
        if (!root) {
            return;
        }
        if (root->children.empty()) {
            words += word + ",";
        }
        for (auto p : root->children) {
            dfs(p.second, word + p.first);
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        TrieNode* root = new TrieNode;
        for (const string& word : split(data, ",")) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode;
                }
                node = node->children.at(c);
            }
        }
        return root;
    }
};
