class Solution {
public:
    /**
     * @param x: the distance from cave A to cave A.
     * @param y: the distance from cave B to cave B.
     * @param z: the distance from cave B to exit C.
     * @return: return the expect distance to go out of the cave.
     */
    int expectDistance(int x, int y, int z) {
        vector<vector<double>> dp(2, vector<double>(100, -1));
        return expectFrom(dp, 0, 1, 1.0, x, y, z) + 0.5;
    }
    
    double expectFrom(vector<vector<double>>& dp, int start, int layer, double p, int x, int y, int z) {
        if (layer >= dp[0].size()) {
            return 0;
        }
        if (dp[start][layer] > 0) {
            return dp[start][layer];
        }
        dp[start][layer] = 0;
        if (start == 0) { // A
            dp[start][layer] += p * 0.5 * x + expectFrom(dp, 0, layer + 1, p * 0.5, x, y, z); // Go to A.
            dp[start][layer] += p * 0.5 * 2 + expectFrom(dp, 1, layer + 1, p * 0.5, x, y, z); // Go to B.
        } else if (start == 1) { // B
            dp[start][layer] += p * 0.5 * y + expectFrom(dp, 0, layer + 1, p * 0.5, x, y, z); // Go to A.
            dp[start][layer] += p * 0.5 * z; // Go to C.
        }
        return dp[start][layer];
    }
};
