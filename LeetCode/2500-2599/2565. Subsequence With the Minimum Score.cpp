class Solution {
public:
    int minimumScore(string s, string t) {
        vector<int> dp(t.length(), -1);
        // Populate the minimum sub-suffix from right to left.
        int r = t.length() - 1;
        for (int i = s.length() - 1; i >= 0 && r >= 0; i--) {
            if (s[i] == t[r]) {
                dp[r--] = i;
            }
        }
        r++;
        int result = r;
        // Scan the shortest sub-prefix from right to left.
        for (int i = 0, j = 0; i < s.length() && j < r; i++) {
            while (r < dp.size() && dp[r] <= i) {
                r++;
            }
            if (s[i] == t[j]) {
                result = min(result, r - j - 1);
                j++;
            }
        }
        
        return result;
    }
};
