template<class T = string>
class Trie {
  public:
    ~Trie() {
        for (auto [c, child] : children_) {
            delete child;
        }
    }
    
    void insert(const string& word, const T& data = T()) {
        Trie* node = this;
        for (const char c : word) {
            if (node->children_.find(c) == node->children_.end()) {
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

    void getAllWords(vector<string>& result) {
        if (!word_.empty()) {
            result.push_back(word_); 
        }
        for (auto [c, node] : children_) {
            if (word_.empty() || c != '/') {
                node->getAllWords(result);
            }
        }
    }
    
  private:
    unordered_map<char, Trie*> children_;
    string word_;
    T data_;
    
    const Trie* getNode(const string& prefix) const {
        const Trie* node = this;
        for (char c : prefix) {
            if (node->children_.find(c) == node->children_.end()) {
                return nullptr;
            }
            node = node->children_.at(c);
        }
        return node;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;

        for (const string& f : folder) {
            if (result.empty() || 
                f.length() < result.back().length() ||
                result.back() != f.substr(0, result.back().length()) || 
                f[result.back().length()] != '/') {
                result.push_back(f);
            }
        }
        return result;
    }

    vector<string> removeSubfolders2(vector<string>& folder) {
        Trie trie;
        for (const string& s : folder) {
            trie.insert(s);
        }
        vector<string> result;
        trie.getAllWords(result);
        return result;
    }
};
