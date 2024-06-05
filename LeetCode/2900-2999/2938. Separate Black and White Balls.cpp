class Solution {
public:
    long long minimumSteps(string s) {
        long long result = 0;
        for (int i = 0, ok = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                result += i - ok;
                ok++;
            }
        }
        return result;
    }
};
