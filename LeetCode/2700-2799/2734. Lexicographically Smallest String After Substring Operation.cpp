class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (s[i] == 'a') {
            i++;
        }
        if (i == s.length()) {
            s[s.length() - 1] = 'z';
            return s;
        }
        
        for (; i < s.length() && s[i] > 'a'; i++) {
            s[i]--;
        }
        return s;
    }
};
