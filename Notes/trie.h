template<class Data = string>
class Trie {
  public:
    Trie() : children(256, nullptr) {}
    ~Trie() {
        for (Trie* child : children) {
            delete child;
        }
    }
    
    void insert(const string& word, const Data& data = Data()) {
        Trie* node = this;
        for (const char c : word) {
            if (!node->children.at(c)) {
                node->children[c] = new Trie;
            }
            node = node->children.at(c);
            node->data = data;
        }
        node->word = word;
    }
    
    Data get(const string& word) const {
        if (const Trie* node = getNode(word)) {
            return node->data;
        }
        return Data();
    }
    
  private:
    vector<Trie*> children;
    string word;
    Data data;
    
    const Trie* getNode(const string& prefix) const {
        const Trie* node = this;
        for (const char c : prefix) {
            if (!(node = node->children.at(c))) {
                return nullptr;
            }
        }
        return node;
    }
};
