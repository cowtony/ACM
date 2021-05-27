class Solution {
public:
    int maxPower(string s) {
        if (s.empty()) {
            return 0;
        }
        int max_len = 1;
        int len = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                len++;
            } else {
                len = 1;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
