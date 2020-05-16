class Solution {
public:
    /**
     * @param s: a string
     * @return: reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order
     */
    string reverseWords(string &s) {
        size_t start = 0, end;
        while (start < s.length()) {
            end = s.find(' ', start);
            if (end == string::npos) {
                end = s.length();
            }
            
            reverse(s.begin() + start, s.begin() + end);
            
            start = end + 1;
        }
        
        return s;
    }
};
