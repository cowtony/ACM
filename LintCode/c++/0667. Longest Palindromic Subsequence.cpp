class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        if (s.empty()) {
            return 0;
        }
        // DP vector (row = length, col = start_idx):
        //    b b b a b
        // 0: 0 0 0 0 0
        // 1: 1 1 1 1 1
        // 2: 2 2 1 1
        // 3: 3 2 3
        // 4: 3 3
        // 5: 4
        vector<int> dp_2(s.length(), 0);
        vector<int> dp_1(s.length(), 1);
        vector<int> dp(s.length(), 1);
        
        for (int len = 2; len <= s.length(); ++len) {
            for (int i = 0; i + len <= s.length(); ++i) {
                if (s[i] == s[i + len - 1]) {
                    dp[i] = dp_2[i + 1] + 2;
                } else {
                    dp[i] = max(dp_1[i], dp_1[i + 1]);
                }
            }
            
            dp_2 = dp_1;
            dp_1 = dp;
        }
        
        return dp[0];
    }
};
