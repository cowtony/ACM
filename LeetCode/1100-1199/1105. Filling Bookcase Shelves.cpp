class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size() + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < books.size(); i++) {
            int sum_width = 0;
            int max_height = 0;
            for (int j = i; j >= 0; j--) {
                sum_width += books[j][0];
                if (sum_width > shelfWidth) {
                    break;
                }
                max_height = max(max_height, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + max_height);
            }
        }
        return dp.back();
    }
};
