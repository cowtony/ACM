class Solution {
public:
    string makeGood(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.length() - 1 and s[i] != s[i + 1] and tolower(s[i]) == tolower(s[i + 1])) {
                i += 2;
            }
            while (i < s.length() and !res.empty() and res.back() != s[i] and tolower(res.back()) == tolower(s[i])) {
                res.pop_back();
                i++;
            }
            if (i < s.length()) {
                res += s[i];
            }
        }
        return res;
    }
};
