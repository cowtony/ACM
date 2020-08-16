class Solution {
public:
    string reverseWords(string s) {
        while (!s.empty() and s.front() == ' ') {
            s = s.substr(1);
        }
        while (!s.empty() and s.back() == ' ') {
            s.pop_back();
        }
        
        size_t start = 0, end;
        while (start < s.length()) {
            end = s.find(' ', start);
            if (end == string::npos) {
                end = s.length();
            }
            
            reverse(s.begin() + start, s.begin() + end);
            
            start = end + 1;
        }
        
        // Or use build in reverse function.
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
        
        int j = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != ' ' or s[i - 1] != ' ') {
                s[j] = s[i];
                j++;
            }
        }
        
        return s.substr(0, j);
    }
};
