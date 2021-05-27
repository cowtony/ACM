// Reference: https://blog.csdn.net/v_july_v/article/details/7041827
class Solution {
public:
    string longestPrefix(string s) {
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
        
        return s.substr(0, next[s.length() - 1]);
    }
};
