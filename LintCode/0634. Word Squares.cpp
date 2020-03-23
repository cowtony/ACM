// LeetCode 425: https://leetcode.com/problems/word-squares/
struct TrieNode {
    TrieNode() {
        sons = vector<TrieNode*>(26, nullptr);
        is_word = false;
        father = nullptr;
    }
    vector<TrieNode*> sons;
    bool is_word;
    string word;
    TrieNode* father;
};

class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    vector<vector<string>> wordSquares(vector<string> &words) {
        if (words.empty()) {
            return {};
        }
        // Build Trie.
        root = new TrieNode;
        for (const string& word : words) {
            addWord(word);
        }

        vector<TrieNode*> answer = vector<TrieNode*>(words.front().length(), root);
        dfs(answer, 0);
        return ret;
    }

private:
    TrieNode* root;
    vector<vector<string>> ret;
    
    void addWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->sons[c - 'a']) {
                node->sons[c - 'a'] = new TrieNode;
                node->sons[c - 'a']->father = node;
            }
            node = node->sons[c - 'a'];
        }
        node->is_word = true;
        node->word = word;
    }
    
    void dfs(vector<TrieNode*>& answer, int depth) {
        if (depth == answer.size()) {
            vector<string> square;
            for (int i = 0; i < answer.size(); i++) {
                square.emplace_back(answer[i]->word);
            }
            ret.emplace_back(square);
            return;
        }
        
        for (string word : searchAll(answer[depth], answer.size() - depth)) {
            // Check disqualify.
            if (!isQualified(answer, word, depth)) {
                continue;
            }

            // Proceed.
            for (int i = 0; i < answer.size(); i++) {
                answer[i] = answer[i]->sons[word[i] - 'a'];
            }
            dfs(answer, depth + 1);
            // Revert
            for (int i = 0; i < answer.size(); i++) {
                answer[i] = answer[i]->father;
            }
            next:;
        }
    }
    
    vector<string> searchAll(TrieNode* node, int remain) const {
        vector<string> ret;
        if (remain == 0) {
            if (node->is_word) {
                ret.push_back(node->word);
            }
            return ret;
        }
        
        for (TrieNode* next : node->sons) {
            if (next) {
                vector<string> ans = searchAll(next, remain - 1);
                ret.insert(ret.end(), ans.begin(), ans.end());
            }
        }
        return ret;
    }
    
    bool isQualified(const vector<TrieNode*>& answer, const string& word, int depth = 0) const {
        for (int i = depth; i < word.length(); i++) {
            if (!answer[i]->sons[word[i] - 'a']) {
                return false;
            }
        }
        return true;
    }
};
