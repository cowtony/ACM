class Solution {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() and s.back() == ' ') {
            s.pop_back();
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                return s.length() - (i + 1);
            }
        }
        return s.length();
    }
};
