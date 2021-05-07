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
    }
    
    Data get(const string& word) const {
        if (const Trie* node = getNode(word)) {
            return node->data;
        }
        return -1;
    }
    
  private:
    vector<Trie*> children;
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

class WordFilter {
  public:
    WordFilter(vector<string>& words) {
        for (int idx = 0; idx < words.size(); idx++) {
            string word = words[idx];
            for (int i = 0; i < word.length(); i++) {
                trie.insert(word.substr(i, word.length() - i) + '|' + word, idx);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return trie.get(suffix + '|' + prefix);
    }
    
  private:
    Trie<int> trie;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
