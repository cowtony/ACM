class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int kMaxHat = 40;
        ppls = vector<vector<int>>(kMaxHat + 1);
        for (int i = 0; i < hats.size(); i++) {
            for (int hat_id : hats.at(i)) {
                ppls[hat_id].push_back(i);
            }
        }
        
        // dp[i][j] means use hat ID under i to solve the j-bit masking people.
        // The bit-masking == 1 indicate who haven't got a hat.
        int num_people = hats.size();
        dp = vector<vector<int>>(kMaxHat + 1, vector<int>(1 << num_people, -1));
        return dfs(40, (1 << num_people) - 1);
    }
    
private:
    vector<vector<int>> ppls;
    vector<vector<int>> dp;
    
    int dfs(int hat, int mask) {
        if (mask == 0) {
            return 1;
        }
        if (hat < 0) {
            return 0;
        }
        if (dp[hat][mask] >= 0) {
            return dp[hat][mask];
        }
        
        int res = dfs(hat - 1, mask); // not using the current hat
        for (int people : ppls.at(hat)) {
            if ((mask & (1 << people)) > 0) {
                res = (res + dfs(hat - 1, mask ^ (1 << people))) % 1000000007;
            }
        }
        return dp[hat][mask] = res;
    }
};
