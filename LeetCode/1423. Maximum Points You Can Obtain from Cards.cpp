class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> prefix_sum(cardPoints.size() + 1, 0);
        for (int i = 0; i < cardPoints.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + cardPoints[i];
        }
        
        vector<int> suffix_sum(cardPoints.size() + 1, 0);
        for (int i = 0; i < cardPoints.size(); i++) {
            suffix_sum[i + 1] = suffix_sum[i] + cardPoints[cardPoints.size() - 1 - i];
        }
        
        int max_sum = INT_MIN;
        for (int i = 0; i <= k; i++) {
            max_sum = max(max_sum, prefix_sum[i] + suffix_sum[k - i]);
        }
        
        return max_sum;
    }
};
