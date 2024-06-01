class Solution {
public:
    int scoreOfString(string s) {
        int result = 0;
        for (int i = 1; i < s.length(); i++) {
            result += abs(s[i - 1] - s[i]);
        }
        return result;
    }
};
