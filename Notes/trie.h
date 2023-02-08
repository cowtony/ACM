template<class T = string>
class Trie {
  public:
    Trie() : children_(256, nullptr) {}
    ~Trie() {
        for (Trie* child : children_) {
            delete child;
        }
    }
    
    void insert(const string& word, const T& data = T()) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children_.at(c)) {
                node->children_[c] = new Trie;
            }
            node = node->children_.at(c);
            node->data_ = data;
        }
        node->word_ = word;
    }
    
    T get(const string& word) const {
        if (const Trie* node = getNode(word_)) {
            return node->data_;
        }
        return T();
    }
    
  private:
    vector<Trie*> children_;
    string word_;
    T data_;
    
    const Trie* getNode(const string& prefix) const {
        const Trie* node = this;
        for (char c : prefix) {
            if (!(node = node->children_.at(c))) {
                return nullptr;
            }
        }
        return node;
    }
};
