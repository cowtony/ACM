class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> index(26);
        for (int i = 0; i < ring.size(); i++) {
            index[ring[i] - 'a'].push_back(i);
        }
        
        vector<int> dp(ring.size());
        for (int idx : index[key[0] - 'a']) {
            dp[idx] = dist(0, idx, ring.size()) + /*press*/1;
        }

        for (int i = 1; i < key.size(); i++) {
            vector<int> new_dp(ring.size(), INT_MAX);
            for (int idx : index[key[i] - 'a']) {
                for (int prev : index[key[i - 1] - 'a']) {
                    new_dp[idx] = min(new_dp[idx], dp[prev] + dist(idx, prev, ring.size()) + /*press*/1);
                }
            }
            dp = new_dp;
        }

        int min_step = INT_MAX;
        for (int idx : index[key.back() - 'a']) {
            min_step = min(min_step, dp[idx]);
        }
        return min_step;
    }

    int dist(int idx1, int idx2, int len) {
        if (idx1 > idx2) {
            return dist(idx2, idx1, len);
        }
        return min(idx2 - idx1, idx1 + len - idx2);
    }
};
