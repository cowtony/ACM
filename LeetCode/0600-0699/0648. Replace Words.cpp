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

    string getEarliest(const string& word) const {
        const Trie* node = this;
        for (char c : word) {
            if (!(node = node->children_.at(c))) {
                return word;
            } else if (!node->word_.empty()) {
                return node->word_;
            }
        }
        return word;
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

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        auto words = split(sentence);
        for (string& word : words) {
            word = trie.getEarliest(word);
        }
        return join(words);
    }

    // Split
    vector<string> split(string s, string delimiter = " ") {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }

    // Join
    string join(const vector<string>& words, const string& delimiter = " ") {
        if (words.empty()) {
            return "";
        }
        string res = words.at(0);
        for (int i = 1; i < words.size(); i++) {
            res += delimiter + words.at(i);
        }
        return res;
    }
};
