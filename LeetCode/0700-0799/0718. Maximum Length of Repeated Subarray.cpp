class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};
