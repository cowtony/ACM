class Solution {
public:
    string reverseWords(string s) {
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
