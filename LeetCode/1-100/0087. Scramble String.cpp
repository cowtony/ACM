class Solution {
public:
    string s_1, s_2;
    vector<vector<vector<int>>> dp;
    
    bool isScramble(string s1, string s2) {
        s_1 = s1;
        s_2 = s2;
        dp = vector<vector<vector<int>>>(s1.length(), vector<vector<int>>(s2.length(), vector<int>(s1.length() + 1, 0)));
        
        return recursive(0, 0, s_1.length());
    }
    
    bool recursive(int i1, int i2, int len) {
        if (dp[i1][i2][len] != 0) {
            return dp[i1][i2][len] == 1;
        }
        if (s_1.substr(i1, len) == s_2.substr(i2, len)) {
            dp[i1][i2][len] = 1;
            return true;
        }
        if (len == 1) {
            dp[i1][i2][len] = (s_1[i1] == s_2[i2]? 1 : -1);
            return s_1[i1] == s_2[i2];
        }
        
        for (int i = 1; i < len; i++) {
            if (recursive(i1, i2, i) and recursive(i1 + i, i2 + i, len - i)) {
                dp[i1][i2][len] = 1;
                return true;
            }
            if (recursive(i1, i2 + len - i, i) and recursive(i1 + i, i2, len - i)) {
                dp[i1][i2][len] = 1;
                return true;
            }
        }
        dp[i1][i2][len] = -1;
        return false;
    }
};
