class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int last_kmp = KMP(s).back();
        return last_kmp > 0 and last_kmp % (s.length() - last_kmp) == 0;
    }
    
    vector<int> KMP(const string& s) {
        vector<int> next(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            int pre = i;
            do {
                if (pre > 0) {
                    pre = next[pre - 1];
                    next[i] = pre + 1;
                } else {
                    next[i] = 0;
                    break;
                }
            } while (s[i] != s[pre]);
        }
        return next;
    }
};
