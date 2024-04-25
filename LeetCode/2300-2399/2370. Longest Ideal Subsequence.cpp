class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        for (int i = 0; i < s.length(); i++) {
            int max_length = 0;
            for (int c = max(0, s[i] - 'a' - k); c <= min(25, s[i] - 'a' + k); c++) {
                max_length = max(max_length, dp[c]);
            }
            dp[s[i] - 'a'] = max_length + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
