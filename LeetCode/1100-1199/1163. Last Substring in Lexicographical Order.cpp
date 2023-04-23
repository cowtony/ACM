class Solution {
public:
    string lastSubstring(string s) {
        int idx = 0;
        for (int i = 1, len = 0; i < s.length(); i++) {
            // cout << "i: " << i << " " << s[i] << " idx: " << idx << " len: " << len << endl;
            if (idx + len == i - len) {
                len = 0;
            }

            if (s[idx + len] == s[i]) {
                len++;
            } else {
                if (s[idx + len] < s[i]) {
                    idx = i - len;
                    i = idx;
                }
                len = 0;
            }
        }
        return s.substr(idx);
    }
};
