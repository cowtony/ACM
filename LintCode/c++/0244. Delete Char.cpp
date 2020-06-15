class Solution {
public:
    /**
     * @param str: the string
     * @param k: the length
     * @return: the substring with  the smallest lexicographic order
     */
    string deleteChar(string &str, int k) {
        int idx = -1;
        string res;
        for (int i = 1; i <= k; i++) {
            char min_c = CHAR_MAX;
            for (int j = idx + 1; j + k - i < str.length(); j++) {
                if (min_c > str[j]) {
                    min_c = str[j];
                    idx = j;
                }
            }
            res += str[idx];
        }
        
        return res;
    }
};
