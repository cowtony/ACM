class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long kMod = 1e9 + 7;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0));
        for (int i = 0; i <= min(zero, limit); i++) {
            dp0[i][0] = 1;
        }

        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0));
        for (int j = 0; j <= min(one, limit); j++) {
            dp1[0][j] = 1;
        }

        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp0[i][j] = dp0[i - 1][j] + dp1[i - 1][j];
                if (i > limit) {
                    dp0[i][j] -= dp1[i - limit - 1][j];
                }
                dp0[i][j] = (dp0[i][j] + kMod) % kMod;
                
                dp1[i][j] = dp0[i][j - 1] + dp1[i][j - 1];
                if (j > limit) {
                    dp1[i][j] -= dp0[i][j - limit - 1];
                }
                dp1[i][j] = (dp1[i][j] + kMod) % kMod;
            }
        }
        
        return (dp0[zero][one] + dp1[zero][one]) % kMod;
    }
};
