class Solution {
public:
    /**
     * @param str: a string
     * @return: return a string
     */
    string reverseWords(string &str) {
        size_t start = 0, end;
        while (start < str.length()) {
            end = str.find(' ', start);
            if (end == string::npos) {
                end = str.length();
            }
            
            reverse(str.begin() + start, str.begin() + end);
            
            start = end + 1;
        }
        
        // Or use build in reverse function.
        for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
            swap(str[i], str[j]);
        }
        
        return str;
    }
};
