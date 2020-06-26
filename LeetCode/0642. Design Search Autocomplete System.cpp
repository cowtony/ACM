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

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); i++) {
            trie.insert(sentences[i], times[i]);
        }
        node = trie.root;
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            node->data++;
            node->word = s;
            node = trie.root;
            s = "";
            return {};
        }
        
        s += c;
        node = Trie<int>::next(node, c);
        priority_queue<Entry> pq;
        dfs(node, pq);
        vector<string> res;
        while (!pq.empty() and res.size() < 3) {
            res.insert(res.begin(), pq.top().s);
            pq.pop();
        }
        return res;
        
    }
    
private:
    Trie<int> trie;
    Trie<int>::Node* node;
    string s = "";
    
    struct Entry {
        int count;
        string s;
        bool operator < (const Entry& e) const {
            if (count == e.count) {
                return s < e.s;
            } else {
                return count > e.count;
            }
        }
    };
    
    void dfs(Trie<int>::Node* node, priority_queue<Entry>& pq) {
        if (node->data > 0) {
            pq.push({node->data, node->word});
            if (pq.size() > 3) {
                pq.pop();
            }
        }
        for (auto next : node->sons) {
            dfs(next.second, pq);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
