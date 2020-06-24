template<class T = string>
class Trie {
public:
    Trie() { root = new TrieNode(); }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons.at(c);
        }
        node->data = word;  // Store data here.
    }
    T get(const string& word) const {
        TrieNode* node = root;
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
        TrieNode* node = root;
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
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> sons;
        T data;
    }*root;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie<> trie;
        for (const string& word : words) {
            trie.insert(word);
        }
        
        unordered_map<string, bool> dp;
        vector<string> res;
        for (const string& word : words) {
            if (isConcatenated(trie, dp, word)) {
                res.push_back(word);
            }
        }
        
        return res;
    }
    
    bool isConcatenated(const Trie<string>& trie, unordered_map<string, bool>& dp, const string& word) {
        if (dp.find(word) != dp.end()) {
            return dp[word];
        }

        for (const string& prefix : trie.getAllPrefix(word)) {
            string remain = word.substr(prefix.length());
            if (!trie.get(remain).empty() or isConcatenated(trie, dp, remain)) {
                return dp[word] = true;
            }
        }
        return dp[word] = false;
    }
};
