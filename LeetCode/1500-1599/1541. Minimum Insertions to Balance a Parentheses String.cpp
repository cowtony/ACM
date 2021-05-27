class Solution {
public:
    int minInsertions(string s) {
        int left = 0, res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (left == 0) {
                    res++;
                } else {
                    left--;
                }
                if (i + 1 >= s.length() or s[i + 1] != ')') {
                    res++;
                } else {
                    i++;
                }
            } else {
                left++;
            }
        }
        
        return res + left * 2;
    }
};
