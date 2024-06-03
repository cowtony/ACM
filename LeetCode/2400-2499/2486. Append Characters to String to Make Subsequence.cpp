class Solution {
public:
    int appendCharacters(string s, string t) {
        int ti = 0;
        for (int si = 0; si < s.length(); si++) {
            if (s[si] == t[ti]) {
                ti++;
                if (ti == t.length()) {
                    return 0;
                }
            }
        }
        return t.length() - ti;
    }
};
