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
    
    bool match(string s, string word) {
        s.push_back('0');
        word.push_back('0');
        
        for (int i = 0, j = 0; i < word.length(); i++, j++) {
            if (s[j] != word[i]) {
                while (j + 1 < s.length() and s[j + 1] == s[j]) {
                    j++;
                }
                if (j < 2 or s.substr(j - 2, 3) != string(3, s[j])) {
                    return false;
                } 
                j++;
                if (j >= s.length() or s[j] != word[i]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
