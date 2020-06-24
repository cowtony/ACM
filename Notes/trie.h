template<class T = string>
class Trie {
public:
    Trie() { root = new TrieNode(); }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons.at(c);
        }
        node->data = word;  // Store data here.
    }
    T get(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                return T();
            }
            node = node->sons.at(c);
        }
        return node->data;
    }
    vector<T> getAllPrefix(const string& word) const {
        vector<T> res;
        TrieNode* node = root;
        for (char c : word.substr(0, word.length() - 1)) {
            if (node->sons.find(c) == node->sons.end()) {
                return res;
            }
            node = node->sons.at(c);
            if (!node->data.empty()) {
                res.push_back(node->data);
            }
        }
        return res;
    }
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> sons;
        T data;
    }*root;
};
