class Solution {
public:
    int climbStairs(int n) {
        vector<int> DP(n + 1, 0);
        DP[0] = 1;
        DP[1] = 2;
        for (int i = 2; i < n; i++)
            DP[i] = DP[i - 1] + DP[i - 2];
        
        return DP[n - 1];
    }
};
