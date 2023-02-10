class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        // dp[2][0b0011] means the best solution for 2 children and only the last two cookies.
        int mask_size = 1 << cookies.size();
        vector<vector<int>> dp(k + 1, vector<int>(mask_size, INT_MAX));
        dp[0][0] = 0;

        // Preprocess the sum of cookies for a given mask.
        vector<int> sum(mask_size, 0);
        for (int mask = 0; mask < mask_size; mask++) {
            for (int i = 0; i < cookies.size(); i++) {
                if (mask & (1 << i)) {
                    sum[mask] += cookies[i];
                }
            }
        }

        for (int i = 1; i <= k; i++) {
            for (int mask = 0; mask < mask_size; mask++) {
                for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                    dp[i][mask] = min(dp[i][mask], max(dp[i - 1][mask ^ submask], sum[submask]));
                }
            }
        }

        return dp[k][mask_size - 1];
    }

    int distributeCookies2(vector<int>& cookies, int k) {
        vector<int> children(k, 0);
        return dfs(cookies, 0, children);
    }

    int dfs(const vector<int>& cookies, int i, vector<int>& children) {
        if (i == cookies.size()) {
            return *max_element(children.begin(), children.end());
        }
        int result = INT_MAX;
        for (int j = 0; j < children.size(); j++) {
            children[j] += cookies[i];
            result = min(result, dfs(cookies, i + 1, children));
            children[j] -= cookies[i];
        }
        return result;
    }
};
