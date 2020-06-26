template<class T = string>
class Trie {
public:
    Trie() { root = new Node(); }
    
    void insert(const string& word, T data = T()) {
        Node* node = root;
        for (char c : word) {
            node = next(node, c);
        }
        node->data = data;  // Store data here.
        node->word = word;
    }
    
    T get(const string& word) const {
        Node* node = root;
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
        Node* node = root;
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
    
// private:
    struct Node {
        unordered_map<char, Node*> sons;
        string word;
        T data = T();
    }*root;
    
    static Node* next(Node* node, char c) {
        if (!node) { return node; }
        if (node->sons.find(c) == node->sons.end()) {
            node->sons[c] = new Node;
        }
        return node->sons.at(c);
    }
};
