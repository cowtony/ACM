class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        dp = vector<vector<int>>(cuts.size(), vector<int>(cuts.size(), -1));
        
        return topDown(cuts, 0, cuts.size() - 1);
    }
    
    vector<vector<int>> dp;
    int topDown(const vector<int>& cuts, int from, int to) {
        if (dp[from][to] != -1) {
            return dp[from][to];
        }
        if (to == from + 1) {
            return dp[from][to] = 0;
        }
        dp[from][to] = INT_MAX;
        for (int cut = from + 1; cut < to; cut++) {
            dp[from][to] = min(dp[from][to], topDown(cuts, from, cut) + topDown(cuts, cut, to) + cuts[to] - cuts[from]);
        }
        return dp[from][to];
    }
};
