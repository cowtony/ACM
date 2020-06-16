class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (const string& word : words) {
            if (match(S, word)) {
                ++res;
            }
        }
        return res;
    }
    
    bool match(const string& s, const string& word) {
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            // cout << i << ' ' << j << endl;
            if (s[i] == word[j]) {
                j++;
            } else if (i >= 2 and s.substr(i - 2, 3) == string(3, s[i])) {
                continue;
            } else if (i >= 1 and i + 1 < s.length() and s.substr(i - 1, 3) == string(3, s[i])) {
                continue;
            } else {
                return false;
            }
        }
        return j == word.length();
    }
};
