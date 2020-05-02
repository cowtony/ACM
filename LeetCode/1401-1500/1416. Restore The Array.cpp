class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<long> dp(s.length(), 0);
        
        for (int i = 0; i < s.length(); i++) {
            long num = 0;
            long base = 1;
            for (int j = i; j >= 0 and base <= k; j--) {
                num += base * (s[j] - '0');
                base *= 10;
                if (num > k) {
                    break;
                }
                if (s[j] == '0') {
                    continue;
                }
                dp[i] = (dp[i] + (j > 0? dp[j - 1] : 1)) % 1000000007;
            }
        }
        return dp[s.length() - 1];
    }
};
