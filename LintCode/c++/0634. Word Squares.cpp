struct TrieNode {
    unordered_map<char, TrieNode*> sons;
    string word;
    TrieNode* father = nullptr;
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
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
                node->sons[c]->father = node;
            }
            node = node->sons.at(c);
        }
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
                answer[i] = answer[i]->sons.at(word[i]);
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
            if (!node->word.empty()) {
                ret.push_back(node->word);
            }
            return ret;
        }
        
        for (pair<char, TrieNode*> next : node->sons) {
            vector<string> ans = searchAll(next.second, remain - 1);
            ret.insert(ret.end(), ans.begin(), ans.end());
        }
        return ret;
    }
    
    bool isQualified(const vector<TrieNode*>& answer, const string& word, int depth = 0) const {
        for (int i = depth; i < word.length(); i++) {
            if (answer[i]->sons.find(word[i]) == answer[i]->sons.end()) {
                return false;
            }
        }
        return true;
    }
};
