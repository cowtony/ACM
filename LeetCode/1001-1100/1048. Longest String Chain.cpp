class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if (words.empty()) {
            return 0;
        }
        vector<unordered_set<string>> words_len(17);
        unordered_map<string, int> chain;
        for (const string& word : words) {
            words_len[word.length()].insert(word);
            chain[word] = 1;
        }
        
        int max_chain = 1;
        for (int len = 16; len > 0; len--) {
            for (const string& word : words_len[len]) {
                for (int i = 0; i < word.length(); i++) {
                    string predecessor = word.substr(0, i) + word.substr(i + 1);
                    if (chain.find(predecessor) != chain.end()) {
                        chain[predecessor] = max(chain[predecessor], chain[word] + 1);
                        max_chain = max(max_chain, chain[predecessor]);
                    }
                }
            }
        }
        
        return max_chain;
    }
};
