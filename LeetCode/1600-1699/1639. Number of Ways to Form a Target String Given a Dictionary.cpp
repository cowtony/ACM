class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<long> dp(target.length() + 1, 0);
        dp[0] = 1;
        for (int col = 0; col < words[0].length(); col++) {
            vector<int> count(26, 0);
            for (const string& word : words) {
                count[word[col] - 'a']++;
            }
            for (int i = target.length() - 1; i >= 0; i--) {
                dp[i + 1] += (dp[i] * count[target[i] - 'a']) % 1000000007;
            }
        }
        return dp[target.length()] % 1000000007;
    }
};
