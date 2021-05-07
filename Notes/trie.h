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

template<class T = string>
class Trie {
  public:
    Trie() : children(26, nullptr) {}
    ~Trie() {
        for (Trie* child : children) {
            delete child;
        }
    }
    
    void insert(const string& word, const T data = T()) {
        Trie* node = this;
        for (const char c : word) {
            if (!node->children.at(c - 'a')) {
                node->children[c - 'a'] = new Trie;
            }
            node = node->children.at(c - 'a');
        }
        node->data = data;  // Store data here.
        node->word = word;
    }
    
    T get(const string& word) const {
        if (Trie* node = getNode(word)) {
            return node->data;
        }
        return T();
    }
    
    vector<T> getAllPrefix(const string& word) const {
        vector<T> res;
        Trie* node = this;
        for (const char c : word.substr(0, word.length() - 1)) {
            if (!(node = node->children.at(c - 'a'))) {
                return res;
            }
            if (!node->data.empty()) {
                res.push_back(node->data);
            }
        }
        return res;
    }
    
    vector<T> getAllData(const string& prefix = "") const {
        const Trie* node = getNode(prefix);
        if (!node) {
            return {};
        }
        // DFS to collect all data.
        vector<T> res;
        if (!node->word.empty()) {
            res.push_back(node->data);
        }
        for (Trie* child : node->children) {
            if (child) {
                vector<T> val = child->getAllData();
                res.insert(res.end(), val.begin(), val.end());
            }
        }
        return res;
    }
    
  private:
    vector<Trie*> children;
    string word;
    T data = T();
    
    const Trie* getNode(const string& prefix) const {
        const Trie* node = this;
        for (const char c : prefix) {
            if (!(node = node->children.at(c - 'a'))) {
                return nullptr;
            }
        }
        return node;
    }
};
