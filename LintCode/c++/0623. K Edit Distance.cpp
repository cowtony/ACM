struct TrieNode {
    unordered_map<char, TrieNode*> sons;
    bool is_word = false;
    string word;
};

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        root = new TrieNode();
        for (const string& word : words) {
            addWord(root, word);
        }
        
        vector<int> dp(target.length() + 1, 0);
        for (int i = 0; i <= target.length(); i++) {
            dp[i] = i;
        }
        dfs(root, target, k, dp);
        return ret;
    }
private:
    TrieNode* root;
    void addWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->sons.find(c) == node->sons.end()) {
                node->sons[c] = new TrieNode;
            }
            node = node->sons[c];
        }
        node->is_word = true;
        node->word = word;
    }
    
    vector<string> ret;
    void dfs(TrieNode* node, const string& target, int k, const vector<int>& dp0) {
        if (node->is_word) {
            if (dp0[target.length()] <= k) {
                ret.emplace_back(node->word);
            }
        }
        for (auto& p : node->sons) {
            vector<int> dp1(target.length() + 1);
            dp1[0] = dp0[0] + 1;
            for (int i = 1; i <= target.length(); i++) {
                dp1[i] = min(dp1[i - 1], min(dp0[i], dp0[i - 1])) + 1;
                if (p.first == target[i - 1]) {
                    dp1[i] = min(dp1[i], dp0[i - 1]);
                }
            }
            dfs(p.second, target, k, dp1);
        }
    }
};
