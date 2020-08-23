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

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string word : words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
    }
    
    bool query(char letter) {
        dq.push_front(letter);
        if (dq.size() > 2000) {
            dq.pop_back();
        }
        
        auto node = trie.root;
        for (auto it = dq.begin(); it != dq.end(); it++) {
            node = node->next(*it);
            if (!node) {
                return false;
            }
            if (!node->word.empty()) {
                return true;
            }
        }
        return false;
    }
    
private:
    Trie<> trie;
    deque<char> dq;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
