class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        if (s.empty()) {
            return s;
        }
        int start, max_length = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1, right = i + 1;
            while (left >= 0 and right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }
                left--;
                right++;
            }
            if (max_length < right - left - 1) {
                max_length = right - left - 1;
                start = left + 1;
            }
            left = i;
            right = i + 1;
            while (left >= 0 and right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }
                left--;
                right++;
            }
            if (max_length < right - left - 1) {
                max_length = right - left - 1;
                start = left + 1;
            }
        }
        return s.substr(start, max_length);
    }
};
