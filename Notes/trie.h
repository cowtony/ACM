template<class T = string>
class Trie {
public:
    Trie() { root = new Node(); }
    
    void insert(const string& word, T data = T()) {
        Node* node = root;
        for (char c : word) {
            node = node->next(c, true);
        }
        node->data = data;  // Store data here.
        node->word = word;
    }
    
    T get(const string& word) const {
        Node* node = root;
        for (char c : word) {
            if (!node = node->next(c)) {
                return T();
            }
        }
        return node->data;
    }
    
    vector<T> getAllPrefix(const string& word) const {
        vector<T> res;
        Node* node = root;
        for (char c : word.substr(0, word.length() - 1)) {
            if (!node = node->next(c)) {
                return res;
            }
            if (!node->data.empty()) {
                res.push_back(node->data);
            }
        }
        return res;
    }
    
// private:
    struct Node {
        Node(): sons(256, nullptr) {}
        vector<Node*> sons;
        string word;
        T data = T();
        Node* next(char c, bool create = false) {
            if (!sons.at(c) and create) {
                sons[c] = new Node;
            }
            return sons.at(c);
        }
    }*root;
};
