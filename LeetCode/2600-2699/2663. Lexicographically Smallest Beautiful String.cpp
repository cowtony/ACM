class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int idx = increment(s, k, s.length() - 1);
        while (idx < s.length()) {
            if (hasPalindrome(s, idx)) {
                idx = increment(s, k, idx);
            } else {
                idx++;
                if (idx < s.length()) {
                    s[idx] = 'a';
                }
            }
        }
        return s;
    }

    int increment(string& s, int k, int i) {
        while (i >= 0 && s[i] - 'a' == k - 1) {
            i--;
        }
        if (i < 0) {
            s = "";
            return 0;
        }
        s[i]++;
        return i;
    }

    bool hasPalindrome(const string& s, int i) {
        if (i > 0 && s[i] == s[i - 1]) {
            return true;
        }
        if (i > 1 && s[i] == s[i - 2]) {
            return true;
        }
        return false;
    }
};
