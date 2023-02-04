class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(order.length());
        for (int i = 0; i < order.length(); i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            if (larger(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }

    bool larger(const string& word1, const string& word2, const vector<int>& rank) {
        for (int i = 0; i < word1.length() && i < word2.length(); i++) {
            if (rank[word1[i] - 'a'] == rank[word2[i] - 'a']) {
                continue;
            }
            return rank[word1[i] - 'a'] > rank[word2[i] - 'a'];
        }
        return word1.length() > word2.length();
    }
};