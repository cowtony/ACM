class Solution {
public:
    string minWindow(string S, string T) {
        // dp[i][j] is the latest start index of matching T[:j] to S[:i]

        //       0  b  d  e
        // 0   : 0 |X  X  X
        // 1(a): 1  X |X  X
        // 2(b): 2 [1] X |X
        // 3(c): 3 [1] X  X
        // 4(d): 4  1  1  X
        // 5(e): 5  1  1  1 <- [1, 5)
        // 6(b): 6  5  1  1
        // 7(d): 7  5 [5] 1
        // 8(d): 8  5  5  1
        // 9(e): 9  5  5  5 <- [5, 9)
        vector<int> dp(T.length() + 1, -1);

        int min_len = INT_MAX;
        string res;
        for (int i = 0; i <= S.length(); i++) {
            for (int j = min(int(T.length()), i); j > 0; j--) {
                if (S[i - 1] == T[j - 1]) {
                    dp[j] = dp[j - 1];
                }
            }
            dp[0] = i;
            
            if (dp[T.length()] >= 0 and i - dp[T.length()] < min_len) {
                min_len = i - dp[T.length()];
                res = S.substr(dp[T.length()], min_len);
            }
        }
        return res;
    }
};
