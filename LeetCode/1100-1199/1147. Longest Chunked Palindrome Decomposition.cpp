class Solution {
public:
    int longestDecomposition(string text) {
        for (int len = 1; len <= text.length() / 2; ++len) {
            int j = text.length() - len;
            if (text.substr(0, len) == text.substr(j)) {
                return 2 + longestDecomposition(text.substr(len, text.length() - 2 * len));
            }
        }
        return text.empty()? 0 : 1;
    }
};
