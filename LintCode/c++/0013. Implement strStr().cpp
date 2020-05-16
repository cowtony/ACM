class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &haystack, string &needle) {
        if (needle.empty()) {
            return 0;
        }
        // Build Next array first. next[i] means the length of longest prefix == suffix for substr(0, i).
        vector<int> next(needle.length(), 0);
        for (int i = 0; i < needle.length(); i++) {
            int pre = i;
            do {
                if (pre > 0) {
                    pre = next[pre - 1];
                    next[i] = pre + 1;
                } else {
                    next[i] = 0;
                    break;
                }
            } while (needle[i] != needle[pre]);
        }
        
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
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
};
