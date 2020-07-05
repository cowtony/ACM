class Solution {
public:
    string decodeString(string s) {
        int i;
        for (i = 0; i < s.length(); i++) {
            if (isdigit(s[i]) or s[i] == '[') {
                break;
            }
        }
        if (i == s.length()) {
            return s;
        }
        
        string res = s.substr(0, i);
        
        int k = 0;
        for (; i < s.length() and s[i] != '['; i++) {
            k = k * 10 + (s[i] - '0');
        }
        
        i++;
        string decode;
        for (int count = 1; i < s.length(); i++) {
            if (s[i] == '[') {
                count++;
            } else if (s[i] == ']') {
                count--;
            }
            if (count == 0) {
                i++;
                break;
            }
            decode += s[i];
        }
        decode = decodeString(decode);
        
        while (k--) {
            res += decode;
        }
        return res + (i == s.length() ? "" : decodeString(s.substr(i)));
    }
};
