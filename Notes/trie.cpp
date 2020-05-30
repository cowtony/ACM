template<class T>
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons.at(c);
        }
        // Store data here.
        node->data = word;
    }
    
    T get(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                return T();
            }
            node = node->sons.at(c);
        }
        return node->data;
    }
    
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> sons;
        T data;
    };
    TrieNode* root;
};
