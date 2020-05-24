class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN / 2));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                dp[i][j] = max({dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1],
                                nums1[i - 1] * nums2[j - 1],
                                dp[i - 1][j],
                                dp[i][j - 1]});
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
