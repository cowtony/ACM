class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int min_len = min(word1.length(), word2.length());
        for (int i = 0; i < min_len; ++i) {
            result += word1[i];
            result += word2[i];
        }
        return result + word1.substr(min_len) + word2.substr(min_len);
    }
};
