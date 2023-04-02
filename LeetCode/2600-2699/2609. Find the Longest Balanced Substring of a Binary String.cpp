class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        s += '0';
        int count_0 = 0, count_1 = 0;
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i] != s[i - 1]) {
                    result = max(result, min(count_0, count_1));
                    count_0 = 0;
                    count_1 = 0;
                }
                count_0++;
            } else {
                count_1++;
            }
        }
        return result * 2;
    }
};
