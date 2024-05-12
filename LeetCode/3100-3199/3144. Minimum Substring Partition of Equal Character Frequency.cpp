class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        result = s.length();
        dp = vector<int>(s.length(), INT_MAX);
        
        
        return dfs(s, 0, 0);
    }
    
    int result;
    vector<int> dp;
    
    int dfs(const string& s, int start, int depth) {
        if (start == s.length()) {
            return 0;
        }
        if (dp[start] != INT_MAX) {
            return dp[start];
        }
        
        vector<int> count(26, 0);
        int unique = 0;
        int max_count = 0;
        
        for (int i = start; i < s.length(); i++) {
            
            if (count[s[i] - 'a'] == 0) {
                unique++;
            }
            max_count = max(max_count, ++count[s[i] - 'a']);
            
            if (max_count * unique == i - start + 1) {
                dp[start] = min(dp[start], dfs(s, i + 1, depth + 1) + 1);
            }
        }
        return dp[start];
    }
};
