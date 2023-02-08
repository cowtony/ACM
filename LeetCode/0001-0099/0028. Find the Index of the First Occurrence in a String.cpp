// KMP algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        vector<int> next = PMT(needle);
        for (int i = 0, j = 0; i < haystack.size(); i++) {
            while (haystack[i] != needle[j]) {
                if (j > 0) {
                    j = next[j - 1];
                } else {
                    j = -1;  // Offset the j++ later.
                    break;
                }
            }
            j++;
            
            // Found a match.
            if (j == needle.length()) {
                return i - (j - 1);
            }
        }
        return -1;
    }

    // Build Next array. next[i] means the length of longest prefix == suffix for substr(0, i).
    vector<int> PMT(const string& s) {
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
