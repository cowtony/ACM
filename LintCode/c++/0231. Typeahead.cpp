template<class T>
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word, const string& value) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons.at(c);
            node->data.insert(value);
        }
    }
    
    T get(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                return T();
            }
            node = node->sons.at(c);
        }
        return node->data;
    }
    
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> sons;
        T data;
    };
    TrieNode* root;
};



class Typeahead {
public:
    /*
    * @param dict: A dictionary of words dict
    */
    Typeahead(unordered_set<string> dict) {
        for (const string& s : dict) {
            string tmp = s;
            while (!tmp.empty()) {
                trie.insert(tmp, s);
                tmp.erase(tmp.begin());
            }
        }
    }

    /*
     * @param str: a string
     * @return: a list of words
     */
    vector<string> search(string &str) {
        set<string> s = trie.get(str);
        return {s.begin(), s.end()};
    }
    
private:
    Trie<set<string>> trie;
};
